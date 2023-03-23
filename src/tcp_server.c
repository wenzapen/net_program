#include "tcp_server.h"


struct TcpServer *tcp_server_new(struct EventLoop *event_loop,
                                    struct Acceptor *acceptor,
                                    connection_completed_callback connection_completed_callback,
                                    message_callback message_callback,
                                    write_completed_callback write_completed_callback,
                                    connection_closed_callback connection_closed_callback,
                                    int thread_num)
{
    struct TcpServer *tcp_server = malloc(sizeof(struct TcpServer));
    tcp_server->event_loop = event_loop;
    tcp_server->acceptor = acceptor;
    tcp_server->connection_completed_callback = connection_completed_callback;
    tcp_server->message_callback = message_callback;
    tcp_server->write_completed_callback = write_completed_callback;
    tcp_server->connection_closed_callback = connection_closed_callback;
    tcp_server->thread_num = thread_num;
    tcp_server->thread_pool = thread_pool_new(event_loop, thread_num);
    tcp_server->data = NULL;

    return tcp_server;
    
}

void tcp_server_start(struct TcpServer *tcp_server)
{
    struct Acceptor *acceptor = tcp_server->acceptor;
    struct EventLoop *event_loop = tcp_server->event_loop;

    thread_pool_start(tcp_server->thread_pool);
}
