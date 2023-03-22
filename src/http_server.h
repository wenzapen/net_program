#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "common.h"

typedef int (*http_request_callback) (struct HttpRequest *http_request, struct HttpResponse *http_response);

struct HttpServer {

    struct TcpServer *tcp_server;
    http_request_callback request_callback;
};

Struct HttpServer *http_server_new(Struct EventLoop *event_loop, int port, http_request_callback request callback, int thread_num);

void http_server_start(Struct HttpServer *http_server);



#endif
