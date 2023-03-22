#include "accptor.h"

struct Acceptor *acceptor_new(int port)
{
    struct Acceptor *acceptor = malloc(sizeof(struct Acceptor));
    acceptor->listen_port = port;
    acceptor->listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    make_nonblocking(acceptor->listen_fd);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(serer_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int on = 1;
    setsockopt(acceptor->listen_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    bind(acceptor->listen_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(acceptor->listen_fd, LISTENQ);

    return acceptor;
}