#include "src/common.h"
#include "src/http_server.h"
#include "src/http_request.h"
#include "src/http_response.h"
#include "src/event_loop.h"

int on_request(struct HttpRequest *http_request, struct HttpResponse *http_response)
{
    char *url = http_request->url;
    char *question = memmem(url, strlen(url), "?", 1);
    char *path = NULL;
    if (question != NULL) {
        path = malloc(question - url);
        strncpy(path, url, question - url);
    } else {
        path = malloc(strlen(url));
        strncpy(path, url, strlen(url));
    }

    if (strcmp(path, "/") == 0) {
        http_response->status_code = OK;
        http_response->status_message = "OK";
        http_response->content_type = "text/html";
        http_response->body = "<html><head><title>This is network programming</title></head><body><h1>Hello, network programming</h1></body></html>";
    } else if (strcmp(path, "/network") == 0) {
        http_response->status_code = OK;
        http_response->status_message = "OK";
        http_response->content_type = "text/plain";
        http_response->body = "hello, network programming";
    } else {
        http_response->status_code = NotFound;
        http_response->status_message = "Not Found";
        http_response->keep_connected = 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    struct EventLoop *event_loop = event_loop_init();
    printf("i am event_loop in main.c %p \n ", event_loop);

    struct HttpServer *http_server = http_server_new(event_loop, SERV_PORT, on_request, 2);

    http_server_start(http_server);

    event_loop_run(event_loop);
}