//
// Created by matteo.simonetti1@stud.unifi.it on 28/12/17.
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

bool seqList_preInsert(struct seqList * list, float val)
{
    if(list->head==(list->tail+1)%list->size)//lista piena
        return false;
    list->head=(list->head-1+list->size)%list->size;
    list->buffer[list->head]=val;
    return true;
}

void seqList_generate(struct seqList * list, int size, int values)
{
    if(values > size)
    {
        printf("ERRORE: si vuole generare una lista sequenziale con troppi valori");
        return;
    }
    seqList_init(list,size);
    int i;
    for(i=0;i<values;i++)
    {
        float val=(float)(rand()%100);
        seqList_preInsert(list, val);
    }
}

bool seqList_sufInsert(struct seqList * list, float val)
{
    if(list->head==(list->tail+1)%list->size)//lista piena
        return false;
    list->buffer[list->tail]=val;
    list->tail=(list->tail+1+list->size)%list->size;
    return true;
}

/*bool seqList_ordInsert(struct seqList * list, float val) //versione ottimizzata: da finire
{
    if(list->head==(list->tail+1)%list->size)//lista piena
        return false;
    int i;
    bool flag=false;
    for(i=list->head;i!=list->tail && !flag;i=(i+1)%list->size)
    {
        if(val>list->buffer[i])
        flag=true;
    }
    if((i-list->head)%list->size < list->size/2)
    {
        int j;
        if(!seqList_preInsert(list,list->buffer[list->head]))
            return false;
        for(j=list->head;j!=(i-1+list->size)%list->size;i=(i+1)%list->size)
        {
            list->buffer[j]=list->buffer[(j+1)%list->size];
        }
        list->buffer[i]=val;
    }
    else
    {

    }
}*/

bool seqList_ordInsert( struct list * ptr, int value)//By Prof. Berretti
{
    int position;
    if( ptr->head != (ptr->tail+1)%ptr->size ) // lista non piena
    {

        for( position = ptr->head; position!=ptr->tail && ptr->buffer[position]<value; )
            position = ( position + 1)%ptr->size;

        int i;
        for( i=ptr->tail; i!=position; i=(i-1+ptr->size)%ptr->size )
            ptr->buffer[i] = ptr->buffer[(i-1+ptr->size)%ptr->size];

        ptr->buffer[position] = value;
        ptr->tail = (ptr->tail+1)%ptr->size;
        return true;
    }
    else
        return false;
}

void seqList_visit(struct seqList * list)
{
    int i;
    for(i=list->head;i!=list->tail;i=(i+1)%list->size)
    {
        printf("\n%.3f",list->buffer[i]);
    }
}

bool seqList_search(struct seqList * list, float val)
{
    bool found=false;
    int i;
    for(i=list->head;i!=list->tail && !found;i=(i+1)%list->size)
    {
        if(isEqual(val, list->buffer[i]))
            found=true;
    }
    return found;
}

bool seqList_preRemove(struct seqList * list, float * val)
{
    if(list->head==list->tail)//lista vuota
        return false;
    list->head=(list->head+1)%list->size;
    return true;
}

#endif //LISTEC_SEQLIST_H
