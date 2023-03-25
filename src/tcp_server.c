#include "tcp_server.h"

#define _GNU_SOURCE

void make_nonblocking(int fd) {
    fcntl(fd, F_SETFL, O_NONBLOCK);
}


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
    struct ThreadPool *tp = thread_pool_new(event_loop, thread_num);
    printf("i am thread_pool(tp) in tcp_server_new function: %p \n", tp);
    tcp_server->thread_pool = tp;
    printf("i am thread_pool in tcp_server_new function: %p \n", tcp_server->thread_pool);
    tcp_server->data = NULL;

    return tcp_server;
    
}

int handle_connection_established(void *data)
{
    struct TcpServer *tcp_server = (struct TcpServer *) data;
    struct Acceptor *acceptor = tcp_server->acceptor;
    int listen_fd = acceptor->listen_fd;

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(struct sockaddr_in);
    int connected_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
    make_nonblocking(connected_fd);

    struct EventLoop *event_loop = thread_pool_get_loop(tcp_server->thread_pool);

    struct TcpConnection *tcp_connection = tcp_connection_new(connected_fd, event_loop, 
                                                            tcp_server->connection_completed_callback,
                                                            tcp_server->message_callback,
                                                            tcp_server->write_completed_callback,
                                                            tcp_server->connection_closed_callback);
    if(tcp_server->data != NULL)
        tcp_connection->data = tcp_server->data;

    return 0;
}

void tcp_server_start(struct TcpServer *tcp_server)
{
    struct Acceptor *acceptor = tcp_server->acceptor;
    struct EventLoop *event_loop = tcp_server->event_loop;

    thread_pool_start(tcp_server->thread_pool);

    struct Channel *channel = channel_new(acceptor->listen_fd, EVENT_READ, handle_connection_established, NULL, tcp_server);
    event_loop_add_channel_event(event_loop, channel->fd, channel);

    return;    
}
