#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include "buffer.h"
#include "common.h"

struct ResponseHeader {
    char *key;
    char *value;
};

enum HttpStatusCode {
    Unkown,
    OK = 200,
    MovedPermently = 301,
    BadRequest = 400,
    NotFound = 404,
};

struct HttpResponse {
    enum HttpStatusCode status_code;
    char *status_message;
    char *content_type;
    char *body;
    struct ResponseHeader *response_headers;
    int response_headers_number;
    int keep_connected;

};

struct HttpResponse *http_response_new();

void http_response_encode_buffer(struct HttpResponse *response, struct Buffer *buffer);


#endif