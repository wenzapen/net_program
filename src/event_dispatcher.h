#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include "channel.h"

struct EventDispatcher {
    const char *name;

    void *(*init)(struct EventLoop *event_loop);
    int (*add)(struct EventLoop *event_loop, struct Channel *channel);
    int (*del)(struct EventLoop *event_loop, struct Channel *channel);
    int (*update)(struct EventLoop *event_loop, struct Channel *channel);
    int (*dispatch)(struct EventLoop *event_loop, struct timeval *);
    int (*clear)(struct EventLoop *event_loop);

};



#endif