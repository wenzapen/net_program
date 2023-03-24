#ifndef COMMON_H
#define COMMON_H

#define _GNU_SOURCE

#include <sys/epoll.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/times.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <pthread.h>
#include <bits/types.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>


#include "utils.h"


void make_nonblocking(int fd);

#define SERV_PORT 43211
#define LISTENQ 1024
#define BUFFER_SIZE 4096


#endif