#ifndef CHANNEL_H
#define CHANNEL_H

#include "common.h"
#include "event_loop.h"

#define EVENT_TIMEOUT 0x01
#define EVENT_READ 0x02
#define EVENT_WRITE 0x04
#define EVENT_SIGNAL 0x08

typedef int (*event_read_callback)(void *data);
typedef int (*event_write_callback)(void *data);

struct Channel {
    int fd;
    int events;
    
    event_read_callback event_read_callback;
    event_write_callback event_write_callback;

    void *data;
};

struct Channel *channel_new(int fd, 
                            int events,
                            event_read_callback event_read_callback,
                            event_write_callback event_write_callback,
                            void *data);


int channel_write_event_is_enabled(struct Channel *channel);

int channel_write_event_enable(struct Channel *channel);

int channel_write_event_disable(struct Channel *channel);


#endif