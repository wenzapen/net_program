#include "http_server.h"


int http_on_connection_completed(struct TcpConnection *tcp_connection) 
{

}

int http_on_message(struct Buffer *buffer, struct TcpConnection *tcp_connection)
{

}

int http_on_write_completed(struct TcpConnection *tcp_connection) 
{

}

int http_on_connection_closed(struct TcpConnection *tcp_connection) 
{

}

Struct HttpServer *http_server_new(Struct EventLoop *event_loop, 
                                    int port, 
                                    http_request_callback request_callback, 
                                    int thread_num)
{
    struct HttpServer *http_server = malloc(sizeof(struct(HttpServer)));
    http_server->http_request_callback = request_callback;
    
    struct Acceptor *acceptor = acceptor_new(port);
    
    http_server->tcp_server = tcp_server_new(event_loop, acceptor, http_on_connection_completed,
                                            http_on_message,
                                            http_on_write_completed,
                                            http_on_connection_closed,
                                            thread_num )
}

void http_server_start(Struct HttpServer *http_server)
{
    tcp_server_start(http_server->tcp_server);
}