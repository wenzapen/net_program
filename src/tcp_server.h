#ifndef TCPSERVER_H
#define TCPSERVER_H

typedef int (*connection_completed_callback) (struct TcpConnection *tcp_connection);
typedef int (*message_callback) (struct Buffer *buffer, struct TcpConnection *tcp_connection);
typedef int (*write_completed_callback) (struct TcpConnection *tcp_connection);
typedef int (*connection_closed_callback) (struct TcpConnection *tcp_connection);

#include "acceptor.h"
#include "event_loop.h"
#include "event_loop_thread.h"
#include "channel.h"
#include "tcp_connection.h"
#include "common.h"



struct TcpServer {
    int port;
    struct EventLoop *event_loop;
    struct Acceptor * acceptor;
    connection_completed_callback connection_completed_callback;
    message_callback message_callback;
    write_completed_callback write_completed_callback;
    connection_closed_callback connection_closed_callback;
    int thread_num;
    struct ThreadPool *thread_pool;
    void *data;
    
};

struct TcpServer *tcp_server_new(struct EventLoop *event_loop,
                                    struct Acceptor *acceptor,
                                    connection_completed_callback connection_completed_callback,
                                    message_callback message_callback,
                                    write_completed_callback write_completed_callback,
                                    connection_closed_callback connection_closed_callback,
                                    int thread_num);

void tcp_server_start(struct TcpServer *tcp_server);



#endif