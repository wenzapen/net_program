#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "event_loop.h"
#include ""

struct TheadPool {
    struct EventPool *main_loop;
    int started;
    int thread_number;
    struct EventLoopThread *event_loop_threads;
    int position;
};

struct ThreadPool *thread_pool_new(struct EventLoop *main_loop, int thread_number);

void thread_pool_start(struct ThreadPool *thread_pool);

#endif