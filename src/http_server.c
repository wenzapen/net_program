#include "http_server.h"


int http_on_connection_completed(struct TcpConnection *tcp_connection) {
    struct HttpRequest *http_request = http_request_new();
    tcp_connection->http_request = http_request;
    return 0;
}

static int process_status_line(char *start, char *end, struct HttpRequest *request) {
    int size = end - start;
    char *space = memmem(start, size, " ", 1);
    assert(space != NULL);
    int method_size = space - start;
    request->method = malloc(method_size + 1);
    strncpy(request->method, start, space - start);
    request->method[method_size + 1] = '\0';

    start = space +1;
    space = memmem(start, end - start, " ", 1);
    assert(space != NULL);
    int url_size = space - start;
    request->url = malloc(url_size + 1);
    strncpy(request->url, start, space - start);
    request->url[url_size + 1] = '\0';

    start = space + 1;
    request->version = malloc(end - start + 1);
    strncpy(request->version, start, end - start);
    request->version[end - start + 1] = '\0';
    assert(space != NULL);

    return size;

}

static int parse_http_request(struct Buffer *buffer, struct HttpRequest *request) {
    int ok = 1;
    while (request->current_state != REQUEST_DONE) {
        if (request->current_state == REQUEST_STATUS) {
            char *crlf = buffer_find_CRLF(buffer);
            if (crlf) {
                int request_line_size = process_status_line(buffer->data + buffer->read_index, crlf, request);
                if (request_line_size) {
                    buffer->read_index += request_line_size;  // request line size
                    buffer->read_index += 2;  //CRLF size
                    request->current_state = REQUEST_HEADERS;
                }
            }
        } else if (request->current_state == REQUEST_HEADERS) {
            char *crlf = buffer_find_CRLF(buffer);
            if (crlf) {
                /**
                 *    <start>-------<colon>:-------<crlf>
                 */
                char *start = buffer->data + buffer->read_index;
                int request_line_size = crlf - start;
                char *colon = memmem(start, request_line_size, ": ", 2);
                if (colon != NULL) {
                    char *key = malloc(colon - start + 1);
                    strncpy(key, start, colon - start);
                    key[colon - start] = '\0';
                    char *value = malloc(crlf - colon - 2 + 1);
                    strncpy(value, colon + 2, crlf - colon - 2);
                    value[crlf - colon - 2] = '\0';

                    http_request_add_header(request, key, value);

                    buffer->read_index += request_line_size;  //request line size
                    buffer->read_index += 2;  //CRLF size
                } else {
                    //读到这里说明:没找到，就说明这个是最后一行
                    buffer->read_index += 2;  //CRLF size
                    request->current_state = REQUEST_DONE;
                }
            }
        }
    }
    return ok;
}

int http_on_message(struct Buffer *input, struct TcpConnection *tcp_connection) {
    struct HttpServer *http_server = (struct HttpServer *) tcp_connection->data;
    struct HttpRequest *http_request = tcp_connection->http_request;

    if (parse_http_request(input, http_request) == 0) {
        char *error_response = "HTTP/1.1 400 Bad Request\r\n\r\n";
        tcp_connection_send_data(tcp_connection, error_response, sizeof(error_response));
        tcp_connection_shutdown(tcp_connection);
    }

    if (http_request_current_state(http_request) == REQUEST_DONE) {
        struct HttpResponse *http_response = http_response_new();
        if(http_server->http_request_callback != NULL) {
            http_server->http_request_callback(http_request, http_response);
        }
        struct Buffer *buffer = buffer_new();
        http_response_encode_buffer(http_response, buffer);
        tcp_connection_send_buffer(tcp_connection, buffer);

        if (http_request_close_connection(http_request)) {
            tcp_connection_shutdown(tcp_connection);
        }
        http_request_reset(http_request);
    }

}

int http_on_write_completed(struct TcpConnection *tcp_connection)  {
    // net_msgx("write completed");
    return 0;
}

int http_on_connection_closed(struct TcpConnection *tcp_connection)  {
    // net_msgx("connection closed");
    if (tcp_connection->http_request != NULL) {
        http_request_clear(tcp_connection->http_request);
        tcp_connection->http_request = NULL;
    }
    return 0;
}

struct HttpServer *http_server_new(struct EventLoop *event_loop, 
                                    int port, 
                                    http_request_callback request_callback, 
                                    int thread_num) {
    struct HttpServer *http_server = malloc(sizeof(struct HttpServer));
    http_server->http_request_callback = request_callback;
    
    struct Acceptor *acceptor = acceptor_new(port);
    
    http_server->tcp_server = tcp_server_new(event_loop, acceptor, http_on_connection_completed,
                                            http_on_message,
                                            http_on_write_completed,
                                            http_on_connection_closed,
                                            thread_num );
    http_server->tcp_server->data = http_server;

    return http_server;
}

void http_server_start(struct HttpServer *http_server) {
    tcp_server_start(http_server->tcp_server);
}