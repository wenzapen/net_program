#include "event_loop_thread.h"
#include "common.h"

void *event_loop_thread_run(void *arg)
{
    struct EventLoopThread *event_loop_thread = (struct EventLoopThread *) arg;
    pthread_mutex_lock(&event_loop_thread->mutex);
    event_loop_thread->event_loop = event_loop_init_with_name(event_loop_thread->thread_name);
    pthread_cond_signal(&event_loop_thread->cond);
    pthread_mutex_unlock(&event_loop_thread->mutex);

    event_loop_run(event_loop_thread->event_loop);
}

int event_loop_thread_init(struct EventLoopThread *event_loop_thread, int i)
{
    pthread_mutex_init(&event_loop_thread->mutex, NULL);
    pthread_cond_init(&event_loop_thread->cond, NULL);

    event_loop_thread->event_loop = NULL;
    event_loop_thread->connection_count = 0;
    event_loop_thread->thread_tid = 0;
    char *buf = malloc(16);
    sprintf(buf, "Thread-%d\0", i+1);
    event_loop_thread->thread_name = buf;   

    return 0;

}

struct EventLoop *event_loop_thread_start(struct EventLoopThread *event_loop_thread)
{
    pthread_create(&event_loop_thread->thread_tid, NULL, &event_loop_thread_run, event_loop_thread);
    
    pthread_mutex_lock(&event_loop_thread->mutex);

    while(event_loop_thread->event_loop == NULL)
        pthread_cond_wait(&event_loop_thread->cond, &event_loop_thread->mutex);
    
    pthread_mutex_unlock(&event_loop_thread->mutex);

    return event_loop_thread->event_loop;


}