#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

struct RequestHeader {
    char *key;
    char *value;

};

enum HttpRequestState {
    REQUEST_STATUS,
    REQUEST_HEADER,
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


#endif