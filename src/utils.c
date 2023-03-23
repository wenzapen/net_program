#include "utils.h"

int is_in_same_thread(struct EventLoop *event_loop)
{
    return event_loop->owner_thread_id == pthread_self();
}