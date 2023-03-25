#ifndef CHANNEL_MAP_H
#define CHANNEL_MAP_H

#include "common.h"

struct ChannelMap {
    void **entries;
    int nentries;

};

int map_make_space(struct ChannelMap *channel_map, int slot, int msize);
void map_init(struct ChannelMap *channel_map);
void map_clear(struct ChannelMap *channel_map);


#endif