#ifndef EVENT_LOOP_THREAD_H
#define EVENT_LOOP_THREAD_H

#include <pthread.h>
#include "event_loop.h"


struct EventLoopThread {
    struct EventLoop *event_loop;
    pthread_t thread_tid;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    char *thread_name;
    long connection_count;
};

int event_loop_thread_init(struct EventLoopThread *event_loop_thread, int i);

struct EventLoop *event_loop_thread_start(struct EventLoopThread *event_loop_thread);


#endif