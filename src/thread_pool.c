#include "thread_pool.h"

struct ThreadPool *thread_pool_new(struct EventLoop *main_loop, int thread_number)
{
    struct ThreadPool *thread_pool = malloc(sizeof(struct ThreadPool));
    thread_pool->main_loop = main_loop;
    thread_pool->position = 0;
    thread_pool->thread_number = thread_number;
    thread_pool->started = 0;
    thread_pool->event_thread_pool = NULL;

    return thread_pool;
}

void thread_pool_start(struct ThreadPool *thread_pool)
{
    assert(!thread_pool->started);
    assert_in_same_thread(thread_pool->main_loop);

    thread_pool->started = 1;
    void *tmp;
    
    if(thread_pool->thread_number <= 0)
        return;
    thread_pool->event_loop_threads = malloc(sizeof(struct EventLoopThread) * thread_pool->thread_number);
    for (int i=0; i<thread_pool->thread_number; i++) 
    {
        event_loop_thread_init(&thread_pool->event_loop_threads[i], i);
        event_loop_thread_start(&thread_pool->event_loop_threads[i]);
    }
}