//
// Created by matteo.simonetti1@stud.unifi.it on 28/12/17.
//

#ifndef LISTEC_PLIST_H
#define LISTEC_PLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "scutils.h"

void pList_preInsert(struct pList ** list, float val);

struct pList
{
    float value;
    struct pList * next;
};

void pList_init(struct pList ** list)
{
    *list= NULL;
}

void pList_generate(struct pList ** list,int size)
{
    *list=NULL;
    int i;
    float val;
    for(i=0;i<size;i++)
    {
        val=(float)(rand()%100);
        pList_preInsert(list,val);
    }
}

void pList_visit(struct pList * list)
{
    for(;list!= NULL;list=list->next)
    {
        printf("\n%.3f",list->value);
    }
}

bool pList_search(struct pList * list, float val)
{
    bool found=false;
    for(;list!=NULL && !found;list=list->next)
    {
        if(isEqual(val,list->value))
            found=true;
    }
    return found;
}

void pList_preInsert(struct pList ** list, float val)
{
    //creo anello
    struct pList * anello=(struct pList *)malloc(sizeof(struct pList));
    if(anello==NULL)
    {
        printf("ERRORE: memoria insufficiente [%d]",__LINE__);
        return;
    }
    anello->value=val;
    anello->next=*list;
    //collego anello
    *list=anello;
}

bool pList_preRemove(struct pList ** list, float * val)
{
    if(*list!=NULL)
    {
        *val=(*list)->value;

        pList * oldFirst=*list;
        *list=(*list)->next;
        free(oldFirst);
        return true;
    }
    return false;
}

bool pList_sufRempve(struct pList ** list, float * val)
{
    while(*list!=NULL)
        list=&((*list)->next);
    return pList_preRemove(list,val);
}

void pList_sufInsert(struct pList ** list, float val)
{
    //scorro la lista fino in fondo
    while(*list!=NULL)
        list=&((*list)->next);
    pList_preInsert(list,val);
}

void pList_ordInsert(struct pList ** list, float val)
{
    while(*list!=NULL && (*list)->value<val)
        list=&(*list)->next;
    pList_preInsert(list,val);
}

#endif //LISTEC_PLIST_H
