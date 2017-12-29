//
// Created by Matteo Simonetti on 28/12/17.
//

#ifndef LISTEC_INDEXLIST_H
#define LISTEC_INDEXLIST_H

#include <stdbool.h>
#include <stdlib.h>

struct indRecord
{
    float value;
    int next;
};

struct indList
{
    int first;
    int size;
    int free;
    struct indRecord * buffer;
};

void indList_init(struct indList * list, int size)
{
    list->buffer=(struct indRecord *)malloc(size* sizeof(indRecord));
    list->size=size;
    list->first=size;
    list->free=0;
    int i;
    for(i=0;i<size;i++)
        list->buffer[i].next=i+1;
}

#endif //LISTEC_INDEXLIST_H
