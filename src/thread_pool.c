#include "thread_pool.h"

struct ThreadPool *thread_pool_new(struct EventLoop *main_loop, int thread_number)
{
    struct ThreadPool *thread_pool = malloc(sizeof(struct ThreadPool));
    // printf("i am thread_pool in thread_pool_new function: %p \n", thread_pool);
    thread_pool->main_loop = main_loop;
    thread_pool->position = 0;
    thread_pool->thread_number = thread_number;
    thread_pool->started = 0;
    thread_pool->event_loop_threads = NULL;

    // printf("i am thread_pool in thread_pool_new function: %p \n", thread_pool);
    
    return thread_pool;
}

void thread_pool_start(struct ThreadPool *thread_pool)
{
    // printf("i am thread_pool: %p \n", thread_pool);
    // printf("i am in void thread_pool_start line 17\n");
    // printf("the value of started is: %d", thread_pool->started);
    assert(!thread_pool->started);
    // assert_in_same_thread(thread_pool->main_loop);
    // printf("i am in void thread_pool_start line 20\n");

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

struct EventLoop *thread_pool_get_loop(struct ThreadPool *thread_pool) {
    struct EventLoop *event_loop;
    event_loop = thread_pool->main_loop;

    if(thread_pool->thread_number > 0) {
        event_loop = thread_pool->event_loop_threads[thread_pool->position].event_loop;
        if (++thread_pool->position >= thread_pool->thread_number) {
            thread_pool->position = 0;
        }
    }
    return event_loop;
}