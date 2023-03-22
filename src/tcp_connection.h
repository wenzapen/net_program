#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

struct TcpConnection {
    struct EventLoop *event_loop;
    struct Channel *channel;
    char *name;
    struct Buffer *input_buffer;
    struct Buffer *output_buffer;

    connection_completed_callback connection_completed_callback;
    message_callback message_callback;
    write_completed_callback write_completed_callback;
    connection_closed_callback connection_closed_callback;

    void *data;
    void *request;
    void *response;

};

struct TcpConnection *tcp_connection_new(int fd,
                                        struct EventLoop *event_loop,
                                        connection_completed_callback connection_completed_callback,
                                        message_callback message_callback,
                                        write_completed_callback write_completed_callback,
                                        connection_closed_callback connection_closed_callback);

#endif