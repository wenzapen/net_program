#include "event_dispatcher.h"
#include "event_loop.h"
#include "common.h"

#define INIT_POLL_SIZE 1024

struct PollDispatcherData {
    int event_count;
    int nfds;
    int realloc_copy;
    struct pollfd *event_set;
    struct poolfd *event_set_copy;
};

static void *poll_init(struct EventLoop *);
static int poll_add(struct EventLoop *event_loop, struct Channel *channel);
static int poll_del(struct EventLoop *event_loop, struct Channel *channel);
static int poll_update(struct EventLoop *event_loop, struct Channel *channel);
static int poll_dispatch(struct EventLoop *event_loop, struct timeval *timeval);
static int poll_clear(struct EventLoop *event_loop);

const struct EventDispatcher poll_dispatcher = {
    "poll",
    poll_init,
    poll_add,
    poll_del,
    poll_update,
    poll_dispatch,
    poll_clear,

};

//init and return poll dispatcher data
void *poll_init(struct EventLoop *event_loop)
{
    struct PollDispatcherData *poll_dispatcher_data = malloc(sizeof(struct PollDispatcherData));
    poll_dispatcher_data->event_set = malloc(sizeof(struct pollfd) * INIT_POLL_SIZE);
    int i;
    for (i=0; i<INIT_POLL_SIZE; i++)
        poll_dispatcher_data->event_set[i].fd = -1;
    poll_dispatcher_data->event_count = 0;
    poll_dispatcher_data->nfds = 0;
    poll_dispatcher_data->realloc_copy = 0;

    return poll_dispatcher_data;

}

int poll_add(struct EventLoop *event_loop, struct Channel *channel)
{
    struct PollDispatcherData *poll_dispatcher_data = (struct PollDispatcherData *) event_loop->event_dispatcher_data;
    int fd = channel->fd;

    int events = 0;
    if(channel->events & EVENT_READ)
        events = events | POLLRDNORM;
    if(channel->events & EVENT_WRITE)
        events = events | POLLWRNORM;

    int i;
    for (i=0; i<INIT_POLL_SIZE; i++)
    {
        if(poll_dispatcher_data->event_set[i].fd < 0)
        {
            poll_dispatcher_data->event_set[i].fd = fd;
            poll_dispatcher_data->event_set[i].events = events;
            break;
        }
    }
    if (i >= INIT_POLL_SIZE) {
        // LOG_ERR("too many clients, just abort it");
    }

    return 0;
}

int poll_del(struct EventLoop *event_loop, struct Channel *channel)
{
    struct PollDispatcherData *poll_dispatcher_data = (struct PollDispatcherData *) event_loop->event_dispatcher_data;
    int fd = channel->fd;

    int i;
    for (i=0; i<INIT_POLL_SIZE; i++)
    {
        if(poll_dispatcher_data->event_set[i].fd = fd)
        {
            poll_dispatcher_data->event_set[i].fd = -1;
            break;
        }
    }
    if (i >= INIT_POLL_SIZE) {
        // LOG_ERR("cannot find fd, delete error");
    }

    return 0;
}

int poll_update(struct EventLoop *event_loop, struct Channel *channel)
{
    struct PollDispatcherData *poll_dispatcher_data = (struct PollDispatcherData *) event_loop->event_dispatcher_data;
    int fd = channel->fd;

    int events = 0;
    if(channel->events & EVENT_READ)
        events = events | POLLRDNORM;
    if(channel->events & EVENT_WRITE)
        events = events | POLLWRNORM;

    int i;
    for (i=0; i<INIT_POLL_SIZE; i++)
    {
        if(poll_dispatcher_data->event_set[i].fd = fd)
        {
            poll_dispatcher_data->event_set[i].events = events;
            break;
        }
    }
    if (i >= INIT_POLL_SIZE) {
        // LOG_ERR("cannot find fd, update error");
    }

    return 0;
}

int poll_dispatch(struct EventLoop *event_loop, struct timeval *timeval)
{
    struct PollDispatcherData *poll_dispatcher_data = (struct PollDispatcherData *) event_loop->event_dispatcher_data;
    int ready_number = 0;
    int time_wait = timeval->tv_sec * 1000;

    if( (ready_number = poll(poll_dispatcher_data->event_set, INIT_POLL_SIZE, time_wait)) < 0 )
    {
        // error(1, errno, "poll failed ");
    }

    if(ready_number <= 0)
        return 0;
    
    int i;
    for (i=0; i<INIT_POLL_SIZE; i++)
    {
        int socket_fd;
        struct pollfd *pollfd = &poll_dispatcher_data->event_set[i];
        if((socket_fd = pollfd->fd) < 0)
            continue;
        if(pollfd->revents > 0)
        {
            if(pollfd->revents & POLLRDNORM)
                channel_event_activate(event_loop, socket_fd, EVENT_READ);
            if(pollfd->revents & POLLWRNORM)
                channel_event_activate(event_loop, socket_fd, EVENT_WRITE);
            if (--ready_number <= 0)
                break;
        }
    }
    return 0;
}

int poll_clear(struct EventLoop *event_loop)
{
    struct PollDispatcherData *poll_dispatcher_data = (struct PollDispatcherData *) event_loop->event_dispatcher_data;
    free(poll_dispatcher_data->event_set);
    poll_dispatcher_data->event_set = NULL;
    free(poll_dispatcher_data);
    event_loop->event_dispatcher_data = NULL;

    return 0;
}