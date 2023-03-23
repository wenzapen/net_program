#include "channel.h"

struct Channel *channel_new(int fd, 
                            int events,
                            event_read_callback event_read_callback,
                            event_write_callback event_write_callback,
                            void *data)
{
    struct Channel *channel = malloc(sizeof(struct Channel));
    channel->fd = fd;
    channel->events = events;
    channel->event_read_callback = event_read_callback;
    channel->event_write_callback = event_write_callback;
    channel->data = data;

    return channel;
}