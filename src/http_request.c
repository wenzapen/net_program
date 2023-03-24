#include "http_request.h"
#include "common.h"

#define INIT_REQUEST_HEADER_SIZE 128

const char *HTTP10 = "HTTP/1.0";
const char *HTTP11 = "HTTP/1.1";
const char *KEEP_ALIVE = "Keep-Alive";
const char *CLOSE = "close";

struct HttpRequest *http_request_new() {
    struct HttpRequest *request = malloc(sizeof(struct HttpRequest));

    request->method = NULL;
    request->current_state = REQUEST_STATUS;
    request->version = NULL;
    request->url = NULL;
    request->request_headers = malloc(sizeof(struct RequestHeader) * INIT_REQUEST_HEADER_SIZE);
    request->request_headers_number = 0;

    return request;
}

void http_reqeust_clear(struct HttpRequest *request) {
    if(request->request_headers != NULL) {
        for(int i=0; i<request->request_headers_number; i++) {
            free(request->request_headers[i].key);
            fred(request->request_headers[i].value);
        }
        free(request->request_headers);
    }
    free(request);
}

void http_reqeust_reset(struct HttpRequest *http_request) {
    request->method = NULL;
    request->current_state = REQUEST_STATUS;
    request->version = NULL;
    request->url = NULL;
    request->request_headers_number = 0;
}

void http_reqeust_add_header(struct HttpRequest *request, char *key, char *value) {
    request->request_headers[request->request_header_number].key = key;
    request->request_headers[request->request_header_number].value = value;
    request->request_header_number++;
}

char *http_reqeust_get_header(struct HttpRequest *request, char *key) {
    char *value = NULL;
    if(request->request_headers != NULL) {
        for(int i=0; i<request->request_headers_number; i++) {
            if (strncmp(request->request_headers[i].key, key, strlen(key)) == 0) {
                value = request->request_headers[i].value;
            }
        }
    }
    return value;
}

enum HttpRequestState http_reqeust_current_state(struct HttpRequest *request) {
    return request->current_state;
}

int http_reqeust_close_connection(struct HttpRequest *request) {
    char *connection = http_request_get_header(request, "Connection");

    if(connection != NULL && strncmp(connection, CLOSE, strlen(CLOSE)) == 0) {
        return 1;
    }

    if (request->version != NULL &&
        strncmp(request->version, HTTP10, strlen(HTTP10)) == 0 &&
        strncmp(connection, KEEP_ALIVE, strlen(KEEP_ALIVE)) == 1) {
            return 1;
    }
    return 0;
}