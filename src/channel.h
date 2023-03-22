#ifndef CHANNEL_H
#define CHANNEL_H


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



#endif