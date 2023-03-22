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

void *poll_init(struct EventLoop *event_loop)
{
    
}