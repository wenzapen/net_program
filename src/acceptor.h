#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include "common.h"

struct Acceptor {
    int listen_port;
    int listen_fd;
};

struct Acceptor *acceptor_new(int port);


#endif