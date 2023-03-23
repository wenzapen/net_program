#include "event_loop.h"
#include "channel_map.h"


struct EventLoop *event_loop_init()
{
    return event_loop_init_with_name(NULL);
}

struct EventLoop *event_loop_init_with_name(char *thread_name)
{
    struct EventLoop *event_loop = malloc(sizeof(struct EventLoop));
    pthread_mutex_init(&event_loop->mutex, NULL);
    pthread_cond_init(&event_loop->cond, NULL);

    if(thread_name != NULL)
        event_loop->thread_name = thread_name;
    else
        event_loop->thread_name = "main thread";
    
    event_loop->quit = 0;
    event_loop->channel_map = malloc(sizeof(struct ChannelMap));
    map_init(event_loop->channel_map);

    event_loop->event_dispatcher = &poll_dispatcher;
    event_loop->event_dispatcher_data = event_loop->event_dispatcher->init(event_loop);

    event_loop->owner_thread_id = pthread_self();
    if(socketpair(AF_UNIX,SOCK_STREAM,0,event_loop->socket_pair) < 0)
        LOG_ERR("socket pair set failed\n");
    event_loop->is_handle_pending = 0;
    event_loop->pending_head = NULL;
    event_loop->pending_tail = NULL;

    struct Channel *channel = channel_new(event_loop->socket_pair[1], EVENT_READ, handle_wakeup,NULL, event_loop);
    event_loop_add_channel_event(event_loop, event_loop->socket_pair[1], channel);

    return event_loop;
}