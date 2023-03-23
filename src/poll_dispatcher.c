#include "event_dispatcher.h"
#include "event_loop.h"

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
static int poll_dispatch(struct EventLoop *event_loop, struct timeval *);
static int poll_clear(struct EventLoop *event_loop);

const struct EventDispatcher poll_dispatcher = {
    "poll",
    poll_init,
    poll_add,
    poll_del,
    poll_update,
    poll_dispatch,
    poll_clear

};

//init and return poll dispatcher data
void *poll_init(struct EventLoop *event_loop)
{
    struct PollDispatcherData *poll_dispatcher_data = malloc(sizeof(struct PollDispatcherData));
    poll_dispather_data->event_set = malloc(sizeof(struct pollfd) * INIT_POLL_SIZE);
    int i;
    for (i=0; i<INIT_POLL_SIZE; i++)
        poll_dispatcher_data->event_set[i].fd = -1;
    poll_dispatcher_data->event_count = 0;
    poll_dispatcher_data->nfds = 0;
    poll_dispatcher_data->realloc_copy = 0;

    return poll_dispatcher_data;

}

