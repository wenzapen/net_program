#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

struct RequestHeader {
    char *key;
    char *value;

};

enum HttpRequestState {
    REQUEST_STATUS,
    REQUEST_HEADERS,
    REQUEST_BODY,
    REQUEST_DONE
};

struct HttpRequest {
    char *version;
    char *method;
    char *url;
    enum HttpRequestState current_state;
    struct RequestHeader *request_headers;
    int request_headers_number;

};

struct HttpRequest *http_request_new();

void http_request_clear(struct HttpRequest *http_request);

void http_request_reset(struct HttpRequest *http_request);

void http_request_add_header(struct HttpRequest *http_request, char *key, char *value);

char *http_request_get_header(struct HttpRequest *http_request, char *key);

enum HttpRequestState http_request_current_state(struct HttpRequest *http_request);

int http_request_close_connection(struct HttpRequest *http_request);


#endif