#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "tcp_server.h"
#include "event_loop.h"
#include "buffer.h"
#include "channel.h"
#include "common.h"

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
    void *http_request;
    void *http_response;

};

struct TcpConnection *tcp_connection_new(int fd,
                                        struct EventLoop *event_loop,
                                        connection_completed_callback connection_completed_callback,
                                        message_callback message_callback,
                                        write_completed_callback write_completed_callback,
                                        connection_closed_callback connection_closed_callback);

int tcp_connection_send_data(struct TcpConnection *tcp_connection, void *data, int size);

int tcp_connection_send_buffer(struct TcpConnection *tcp_connection, struct Buffer *buffer);

void tcp_connection_shutdown(struct TcpConnection *tcp_connection);


#endif