#include "channel.h"

struct Channel *channel_new(int fd, 
                            int events,
                            event_read_callback event_read_callback,
                            event_write_callback event_write_callback,
                            void *data) {
    struct Channel *channel = malloc(sizeof(struct Channel));
    channel->fd = fd;
    channel->events = events;
    channel->event_read_callback = event_read_callback;
    channel->event_write_callback = event_write_callback;
    channel->data = data;

    return channel;
}

int channel_write_event_is_enabled(struct Channel *channel) {
    return channel->events & EVENT_WRITE;
}

int channel_write_event_enable(struct Channel *channel) {
    // printf("envent_write is enabled for channel %d\n", channel->fd);
    struct EventLoop *event_loop = (struct EventLoop *) channel->data;
    channel->events |= EVENT_WRITE;
    event_loop_update_channel_event(event_loop, channel->fd, channel);
}

int channel_write_event_disable(struct Channel *channel) {
    struct EventLoop *event_loop = (struct EventLoop *) channel->data;
    channel->events &~ EVENT_WRITE;
    event_loop_update_channel_event(event_loop, channel->fd, channel);
}