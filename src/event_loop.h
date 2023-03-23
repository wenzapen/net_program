#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "common.h"
#include "event_dispatcher.h"
#include "event_loop.h"
#include "channel.h"

extern const struct EventDispatcher poll_dispatcher;


struct ChannelElement {
    int type;
    struct Channel *channel;
    struct ChannelElement *next;
};

struct EventLoop {
    int quit;
    const struct EventDispatcher *event_dispatcher;
    void *event_dispatcher_data;
    struct ChannelMap *channel_map;
    int is_handle_pending;
    struct ChannelElement *pending_head;
    struct ChannelElement *pending_tail;

    pthread_t owner_thread_id;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int socket_pair[2];
    char *thread_name;
};

struct EventLoop *event_loop_init();
struct EventLoop *event_loop_init_with_name(char *thread_name);
int event_loop_run(struct EventLoop *event_loop);
void event_loop_wakeup(struct EventLoop *event_loop);
int event_loop_add_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel);
int event_loop_remove_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel);
int event_loop_update_channel_event(struct EventLoop *event_loop, int fd, struct Channel *channel);
int event_loop_handle_pending_add(struct EventLoop *event_loop, int fd, struct Channel *channel);
int event_loop_handle_pending_remove(struct EventLoop *event_loop, int fd, struct Channel *channel);
int event_loop_handle_pending_update(struct EventLoop *event_loop, int fd, struct Channel *channel);

int channel_event_activate(struct EventLoop *event_loop, int fd, int revent);


#endif
