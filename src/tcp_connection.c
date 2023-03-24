#include "tcp_connection.h"


int handle_read(void *data)
{

}

int handle_write(void *data)
{

}


struct TcpConnection *tcp_connection_new(int fd,
                                        struct EventLoop *event_loop,
                                        connection_completed_callback connection_completed_callback,
                                        message_callback message_callback,
                                        write_completed_callback write_completed_callback,
                                        connection_closed_callback connection_closed_callback)
{

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
    
}

int tcp_connection_send_buffer(struct TcpConnection *tcp_connection, struct Buffer *buffer) {

}

void tcp_connection_shutdown(struct TcpConnection *tcp_connection) {

}