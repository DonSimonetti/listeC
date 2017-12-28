//
// Created by Matteo Simonetti on 28/12/17.
//

#ifndef LISTEC_SEQLIST_H
#define LISTEC_SEQLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "scutils.h"

struct seqList
{
    float * buffer;
    int head;
    int tail;
    int size;
};

void seqList_init(struct seqList * list,int size)
{
    list->buffer=(float *)malloc(sizeof(float)*size);
    if(list->buffer==NULL)
    {
        printf("ERRORE: impossibile allocare memoria per lista sequenziale");
        return;
    }
    list->size=size;
    list->head=0;
    list->tail=0;
}

void seqList_preInsert(struct seqList * list, float val)
{
    
}

#endif //LISTEC_SEQLIST_H
