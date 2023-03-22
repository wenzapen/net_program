


struct TcpConnection *tcp_connection_new(int fd,
                                        struct EventLoop *event_loop,
                                        connection_completed_callback connection_completed_callback,
                                        message_callback message_callback,
                                        write_completed_callback write_completed_callback,
                                        connection_closed_callback connection_closed_callback)
{

    struct TcpConnection *tcp_connection = malloc(sizeof(struct(TcpConnection)));

    tcp_connection->connection_completed_callback = connection_completed_callback;
    tcp_connection->message_callback = message_callback;
    tcp_connection->write_completed_callback = write_completed_callback;
    tcp_connection->connection_closed_callback = connection_closed_callback;
    tcp_connection->event_loop = event_loop;
    tcp_connection->input_buffer = buffer_new();
    tcp_connection->output_buffer = buffer_new();

    char *buf = malloc(16);
    sprintf(buf, "connection-%d\0", fd);
    tcp_connection->name = buf;

    struct Channel *channel = 


}