#include "src/common.h"

int on_request(struct HttpReqeust *http_request, struct HttpResponse *http_response)
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
        http_response->statusCode = OK;
        http_response->statusMessage = "OK";
        http_response->contentType = "text/html";
        http_response->body = "<html><head><title>This is network programming</title></head><body><h1>Hello, network programming</h1></body></html>";
    } else if (strcmp(path, "/network") == 0) {
        http_response->statusCode = OK;
        http_response->statusMessage = "OK";
        http_response->contentType = "text/plain";
        http_response->body = "hello, network programming";
    } else {
        http_response->statusCode = NotFound;
        http_response->statusMessage = "Not Found";
        http_response->keep_connected = 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    struct EventLoop *event_loop = event_loop_init();

    struct HttpServer *http_server = http_server_new(event_loop, SERV_PORT, on_request, 2);

    http_server_start(http_server);

    event_loop_run(event_loop);
}