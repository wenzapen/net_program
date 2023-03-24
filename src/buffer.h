#ifndef BUFFER_H
#define BUFFER_H



struct Buffer {
    char *data;
    int read_index;
    int write_index;
    int total_size
};

struct Buffer *buffer_new();
void buffer_free(struct Buffer *buffer);
int buffer_writeable_size(struct Buffer *buffer);
int buffer_readable_size(struct Buffer *buffer);
int buffer_front_spare_size(struct Buffer *buffer);

int buffer_append(struct Buffer *buffer, void *data, int size);
int buffer_append_char(struct Buffer *buffer, char data);
int buffer_append_string(struct Buffer *buffer, char *data);
int buffer_socket_read(struct Buffer *buffer, int fd);
char buffer_read_char(struct Buffer *buffer);
char *buffer_find_CRLF(struct Buffer *buffer);

#endif
