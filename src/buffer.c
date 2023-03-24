#include "buffer.h"
#include "common.h"

const char *CRLF = "\r\n";

struct Buffer *buffer_new()
{
    struct Buffer *buffer = malloc(sizeof(struct Buffer));
    if(!buffer)
        return NULL;

    buffer->data = malloc(INIT_BUFFER_SIZE);
    buffer->total_size = INIT_BUFFER_SIZE;
    buffer->read_index = 0;
    buffer->write_index = 0;

    return buffer;
}
void buffer_free(struct Buffer *buffer) {
    free(buffer->data);
    free(buffer);
}
int buffer_writeable_size(struct Buffer *buffer) {
    return buffer->total_size - buffer->write_index;
}
int buffer_readable_size(struct Buffer *buffer) {
    return buffer->write_index - buffer->read_index;
}
int buffer_front_spare_size(struct Buffer *buffer) {
    return buffer->read_index;
}

static void make_room(struct Buffer *buffer, int size) {
    if(buffer_writeable_size(buffer) > size)
        return;
    if(buffer_front_spare_size(buffer) + buffer_writeable_size(buffer) > size) {
        int readable = buffer_readable_size(buffer);
        for(int i=0; i<readable; i++) {
            memcpy(buffer->data+i, buffer->data+buffer->read_index+i, 1);
        }
        buffer->read_index = 0;
        buffer->write_index = readable;
    }
    else {
        void *tmp = realloc(buffer->data, buffer->total_size+size);
        if(tmp == NULL)
            return;
        buffer->data = tmp;
        buffer->total_size += size;
    }
}

int buffer_append(struct Buffer *buffer, void *data, int size) {
    if(data != NULL) {
        make_room(buffer, size);
        memcpy(buffer->data+buffer->write_index, data, size);
        buffer->total_size += size;
    }
}
int buffer_append_char(struct Buffer *buffer, char data) {
    make_room(buffer, 1);
    buffer->data[buffer->write_index++] = data;
}
int buffer_append_string(struct Buffer *buffer, char *data) {
    if(data != NULL) {
        int size = strlen(data);
        buffer_append(buffer, data, size);
    }
}
int buffer_socket_read(struct Buffer *buffer, int fd) {
    char additional_buffer[INIT_BUFFER_SIZE];
    struct iovec vec[2];
    int max_writable_size = buffer_writeable_size(buffer);
    vec[0].iov_base = buffer->data +buffer->write_index;
    vec[0].iov_len = max_writable_size;
    vec[1].iov_base = &additional_buffer;
    vec[1].iov_len = sizeof(additional_buffer);

    int result = readv(fd, vec, 2);
    if(result < 0)
        return -1;
    else if(result <= max_writable_size) {
        buffer->write_index += result;
    } else {
        buffer->write_index = buffer->total_size;
        buffer_append(buffer, &additional_buffer, result - max_writable_size);
    }
    return result;
}

char buffer_read_char(struct Buffer *buffer) {
    char c = buffer->data[buffer->read_index];
    buffer->read_index++;
    return c;
}
char *buffer_find_CRLF(struct Buffer *buffer) {
    char *crlf = memmem(buffer->data + buffer->read_index, buffer_readable_size(buffer), CRLF, 2);
    return crlf;
}