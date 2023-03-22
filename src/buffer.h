#ifndef BUFFER_H
#define BUFFER_H



struct Buffer {
    char *data;
    int read_index;
    int write_index;
    int total_size
};

struct Buffer *buffer_new();


#endif
