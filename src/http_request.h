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
    int request_header_number;

};

struct HttpRequest *http_request_new();

void http_reqeust_clear(struct HttpRequest *http_request);

void http_reqeust_reset(struct HttpRequest *http_request);

void http_reqeust_add_header(struct HttpRequest *http_request, char *key, char *value);

char *http_reqeust_get_header(struct HttpRequest *http_request, char *key);

enum HttpRequestState http_reqeust_current_state(struct HttpRequest *http_request);

int http_reqeust_close_connection(struct HttpRequest *http_request);


#endif