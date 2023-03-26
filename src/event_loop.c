#include "event_loop.h"
#include "channel_map.h"



static int event_loop_handle_pending_channel(struct EventLoop *event_loop)
{
    pthread_mutex_lock(&event_loop->mutex);
    event_loop->is_handle_pending = 1;

    struct ChannelElement *channel_element = event_loop->pending_head;
    while(channel_element != NULL)
    {
        struct Channel *channel = channel_element->channel;
        int fd = channel->fd;
        if(channel_element->type == 1)
            event_loop_handle_pending_add(event_loop, fd, channel);
        else if(channel_element->type == 2)
            event_loop_handle_pending_remove(event_loop, fd, channel);
        else if(channel_element->type == 3)
            event_loop_handle_pending_update(event_loop, fd, channel);
        
        channel_element = channel_element->next;
    }

    event_loop->pending_head = event_loop->pending_tail = NULL;
    event_loop->is_handle_pending = 0;

    pthread_mutex_unlock(&event_loop->mutex);

    return 0;
} 

static void event_loop_channel_buffer_nolock(struct EventLoop *event_loop, int fd, struct Channel *channel, int type) 
{
    struct ChannelElement *channel_element = malloc(sizeof(struct ChannelElement));
    channel_element->channel = channel;
    channel_element->type = type;
    channel_element->next = NULL;

    if(event_loop->pending_head == NULL)
    {
        event_loop->pending_head = event_loop->pending_tail = channel_element;
    }  
    else
    {
        event_loop->pending_tail->next = channel_element;
        event_loop->pending_tail = channel_element;
        
    }  

}

static int event_loop_do_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel, int type)
{
    pthread_mutex_lock(&event_loop->mutex);
    event_loop_channel_buffer_nolock(event_loop, fd, channel, type);
    pthread_mutex_unlock(&event_loop->mutex);

    if(is_in_same_thread(event_loop))
        event_loop_wakeup(event_loop);
    else
        event_loop_handle_pending_channel(event_loop);

    return 0;
}

int event_loop_run(struct EventLoop *event_loop)
{
    struct EventDispatcher *event_dispatcher = event_loop->event_dispatcher;
    struct timeval tv;
    tv.tv_sec = 1;

    while(!event_loop->quit)
    {
        event_dispatcher->dispatch(event_loop, &tv);

        event_loop_handle_pending_channel(event_loop);
    }

    return 0;

}

void event_loop_wakeup(struct EventLoop *event_loop)
{
    char one = 'a';
    // printf("socket pair[0]: %d\n", event_loop->socket_pair[0]);
    ssize_t n = write(event_loop->socket_pair[0], &one, sizeof(one));

    // if(n != sizeof(one))
        // LOG_ERR("wakeup event loop thread failed"); 
}

int event_loop_add_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel)
{
    return event_loop_do_channel_event(event_loop, fd, channel, 1);
}

int event_loop_remove_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel)
{
    return event_loop_do_channel_event(event_loop, fd, channel, 2);
}

int event_loop_update_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel)
{
    return event_loop_do_channel_event(event_loop, fd, channel, 3);    
}

int event_loop_handle_pending_add(struct EventLoop *event_loop, int fd, struct Channel *channel)
{
    struct ChannelMap *channel_map = event_loop->channel_map;
    if(fd>channel_map->nentries)
    {
        if(map_make_space(channel_map, fd, sizeof(struct Channel *)) == -1)
            return -1;
    }

    if(channel_map->entries[fd] == NULL) 
    {
        channel_map->entries[fd] = channel;

        struct EventDispatcher *dispatcher = event_loop->event_dispatcher;
        dispatcher->add(event_loop, channel);
        return 1;
    }
    return 0;
}

int event_loop_handle_pending_remove(struct EventLoop *event_loop, int fd, struct Channel *channel)
{
    struct ChannelMap *channel_map = event_loop->channel_map;
    assert(fd == channel->fd);

    if(fd < 0)
        return 0;
    
    if(fd >= channel_map->nentries)
        return -1;

    struct EventDispatcher *dispatcher = event_loop->event_dispatcher;

    struct Channel *ch = channel_map->entries[fd];

    int rval = 0;

    if((dispatcher->del(event_loop, ch)) == -1)
        rval = -1;
    else
        rval = 1;
   
    channel_map->entries[fd] = NULL;
    return rval;
}

int event_loop_handle_pending_update(struct EventLoop *event_loop, int fd, struct Channel *channel)
{
    struct ChannelMap *channel_map = event_loop->channel_map;
    assert(fd == channel->fd);

    if(fd < 0)
        return 0;
    
    if((channel_map)->entries[fd] == NULL)
        return -1;

    struct EventDispatcher *dispatcher = event_loop->event_dispatcher;

    return dispatcher->update(event_loop, channel);

}

int channel_event_activate(struct EventLoop *event_loop, int fd, int revent)
{
    struct ChannelMap *channel_map = event_loop->channel_map;
    

    if(fd < 0)
        return 0;
    
    if(fd >= channel_map->nentries)
        return -1;

    struct Channel *channel = channel_map->entries[fd];
    // printf("i am channel in channel_event_activate %p \n ", channel);
    // printf("i am fd from parameter: %d and from channel %d in channel_event_activate %p \n ", fd, channel->fd);
    assert(fd == channel->fd);

    if(revent & EVENT_READ)
        if(channel->event_read_callback) channel->event_read_callback(channel->data);
    if(revent & EVENT_WRITE)
        if(channel->event_write_callback) channel->event_write_callback(channel->data);

   return 0;
}

static int handle_wakeup(void *data) {
    struct EventLoop *event_loop = (struct EventLoop *) data;
    char one;
    ssize_t n = read(event_loop->socket_pair[1], &one, sizeof one);
    if (n != sizeof one) {
        // LOG_ERR("handleWakeup  failed");
    }
    // net_msgx("wakeup, %s", event_loop->thread_name);
}


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
    if(socketpair(AF_UNIX,SOCK_STREAM,0,event_loop->socket_pair) < 0) {
        // LOG_ERR("socket pair set failed\n");
    }

    event_loop->is_handle_pending = 0;
    event_loop->pending_head = NULL;
    event_loop->pending_tail = NULL;

    struct Channel *channel = channel_new(event_loop->socket_pair[1], EVENT_READ, handle_wakeup,NULL, event_loop);
    event_loop_add_channel_event(event_loop, event_loop->socket_pair[1], channel);

    return event_loop;
}