//
// Created by matteo.simonetti1@stud.unifi.it on 28/12/17.
//

#ifndef LISTEC_INDEXLIST_H
#define LISTEC_INDEXLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

void indList_preInsert(struct indList * list, float val)
{
    if(list->free==list->size)
    {
        printf("lista piena");
        return;
    }
    int oldFree=list->free;
    list->free=((list->buffer)[list->free]).next;
    list->buffer[oldFree].value=val;
    list->buffer[oldFree].next=list->first;
    list->first=oldFree;
}

/*void indList_sufInsert(struct indList * list, float val)
{
    if(list->free==list->size)
    {
        printf("lista piena");
        return;
    }
    in
}*/


#endif //LISTEC_INDEXLIST_H
