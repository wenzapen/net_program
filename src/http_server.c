#include "http_server.h"


int http_on_connection_completed(struct TcpConnection *tcp_connection) {
    struct HttpRequest *http_request = http_request_new();
    tcp_connection->http_request = http_request;
    return 0;
}

static int process_status_line(char *start, char *end, struct HttpRequest *request) {
    
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

int http_on_message(struct Buffer *buffer, struct TcpConnection *tcp_connection)
{

}

int http_on_write_completed(struct TcpConnection *tcp_connection) 
{

}

int http_on_connection_closed(struct TcpConnection *tcp_connection) 
{

}

Struct HttpServer *http_server_new(Struct EventLoop *event_loop, 
                                    int port, 
                                    http_request_callback request_callback, 
                                    int thread_num)
{
    struct HttpServer *http_server = malloc(sizeof(struct(HttpServer)));
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

void http_server_start(Struct HttpServer *http_server)
{
    tcp_server_start(http_server->tcp_server);
}