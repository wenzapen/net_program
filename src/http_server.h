#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "common.h"
#include "event_loop.h"
#include "tcp_server.h"
#include "tcp_connection.h"
#include "http_request.h"
#include "http_response.h"

typedef int (*http_request_callback) (struct HttpRequest *http_request, struct HttpResponse *http_response);

struct HttpServer {

    struct TcpServer *tcp_server;
    http_request_callback http_request_callback;
};

struct HttpServer *http_server_new(struct EventLoop *event_loop, int port, http_request_callback request_callback, int thread_num);

void http_server_start(struct HttpServer *http_server);



#endif
