#include "http_response.h"
#include "common.h"

#define INIT_RESPONSE_HEADER_SIZE 128

struct HttpResponse *http_response_new() {
    struct HttpResponse *response = malloc(sizeof(struct HttpResponse));
    response->body = NULL;
    response->status_code = Unkown;
    response->status_message = NULL;
    response->response_headers = malloc(sizeof(struct ResponseHeader) * INIT_RESPONSE_HEADER_SIZE);
    response->response_headers_number = 0;
    response->keep_connected = 0;

    return response;
}

void http_response_encode_buffer(struct HttpResponse *response, struct Buffer *output) {
    char buf[32];
    snprintf(buf, sizeof(buf), "HTTP/1.1 %d", response->status_code);
    buffer_append_string(output, buf);
    buffer_append_string(output, response->status_message);
    buffer_append_string(output, "\r\n");

    if(response->keep_connected) {
        buffer_append_string(output, "Connection: close\r\n");
    } else {
        snprintf(buf, sizeof(buf), "Content-Length: %zd\r\n", strlen(response->body));
        buffer_append_string(output, buf);
        buffer_append_string(output, "Connection: Keep-Alive\r\n");
    }

    if(response->response_headers != NULL && response->response_headers_number > 0 ) {
        for (int i=0; i<response->response_headers_number; i++ ) {
            buffer_append_string(output, response->response_headers[i].key);
            buffer_append_string(output, ": ");
            buffer_append_string(output, response->response_headers[i].value);
            buffer_append_string(output, "\r\n");
        }
    }
    buffer_append_string(output, "\r\n");
    buffer_append_string(output, response->body);

}