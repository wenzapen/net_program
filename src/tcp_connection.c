#include "tcp_connection.h"

static int handle_connection_closed(struct TcpConnection *tcp_connection) {
    struct EventLoop *event_loop = tcp_connection->event_loop;
    struct Channel *channel = tcp_connection->channel;

    event_loop_remove_channel_event(event_loop, channel->fd, channel);

    if(tcp_connection->connection_closed_callback != NULL) 
        tcp_connection->connection_closed_callback(tcp_connection);
}


int handle_read(void *data){
    struct TcpConnection *tcp_connection = (struct TcpConnection *) data;
    struct Buffer *input_buffer = tcp_connection->input_buffer;
    struct Channel *channel = tcp_connection->channel;

    if (buffer_socket_read(input_buffer, channel->fd) > 0) {
        if(tcp_connection->message_callback != NULL) {
            tcp_connection->message_callback(tcp_connection);
        }
    } else {
        handle_connection_closed(tcp_connection);
    }

}

int handle_write(void *data) {
    struct TcpConnection *tcp_connection = (struct TcpConnection *) data;
    struct EventLoop *event_loop = tcp_connection->event_loop;

    struct Buffer *output = tcp_connection->output_buffer;
    struct Channel *channel = tcp_connection->channel;

    ssize_t nwrited = write(channel->fd, output->data+output->read_index, buffer_readable_size(output));

    if (nwrited > 0) {
        output->read_index += nwrited;
        if (buffer_readable_size(output) == 0) {
            channel_write_event_disable(channel);
        }

        if (tcp_connection->write_completed_callback != NULL) 
            tcp_connection->write_completed_callback(tcp_connection);
    }

}


struct TcpConnection *tcp_connection_new(int fd,
                                        struct EventLoop *event_loop,
                                        connection_completed_callback connection_completed_callback,
                                        message_callback message_callback,
                                        write_completed_callback write_completed_callback,
                                        connection_closed_callback connection_closed_callback) {

    struct TcpConnection *tcp_connection = malloc(sizeof(struct(TcpConnection)));

    tcp_connection->connection_completed_callback = connection_completed_callback;
    tcp_connection->message_callback = message_callback;
    tcp_connection->write_completed_callback = write_completed_callback;
    tcp_connection->connection_closed_callback = connection_closed_callback;
    tcp_connection->event_loop = event_loop;
    tcp_connection->input_buffer = buffer_new();
    tcp_connection->output_buffer = buffer_new();

    char *buf = malloc(16);
    sprintf(buf, "connection-%d\0", fd);
    tcp_connection->name = buf;

    struct Channel *channel = channel_new(fd, EVENT_READ, handle_read, handle_write, tcp_connection);
    tcp_connection->channel = channel;

    if(tcp_connection->connection_completed_callback != NULL)
        tcp_connection->connection_completed_callback(tcp_connection);
    
    event_loop_add_channel_event(tcp_connection->event_loop, fd, tcp_connection->channel);

    return tcp_connection;


}

int tcp_connection_send_data(struct TcpConnection *tcp_connection, void *data, int size) {
    size_t nwrited = 0;
    size_t nleft = size;
    int fault = 0;

    struct Buffer *output_buffer = tcp_connection->output_buffer;
    struct Channel *channel = tcp_connection->channel;

    if (!channel_write_event_is_enabled(channel) && buffer_readable_size(output_buffer) == 0) {
        nwrited = write(channel->fd, data, size);
        if (nwrited >= 0) {
            nleft -= nwrited;
        } else {
            nwrited = 0;
            if (errno != EWOULDBLOCK) {
                if (errno == EPIPE || errno == ECONNRESET) {
                    fault = 1;
                }
            }
        }
    }

    if (!fault && nleft > 0) {
        buffer_append(output_buffer, data+nwrited, nleft);
        if (!channel_write_event_is_enabled(channel)) 
            channel_write_event_enable(channel);
    }
    return nwrited;
}

int tcp_connection_send_buffer(struct TcpConnection *tcp_connection, struct Buffer *buffer) {
    int size = buffer_readable_size(buffer);
    int nsent = tcp_connection_send_data(tcp_connection, buffer->data + buffer->read_index, size);
    buffer->read_index += nsent;

    return nsent;
}

void tcp_connection_shutdown(struct TcpConnection *tcp_connection) {
    if (shutdown(tcp_connection->channel->fd, SHUT_WR) < 0)
        net_msgx("tcp connection shutdown failed. Socket id=%d", tcp_connection->channel->fd);
}