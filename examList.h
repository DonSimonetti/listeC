//
// Created by Matteo Simonetti on 11/01/18.
//

#ifndef LISTEC_EXAMLIST_H
#define LISTEC_EXAMLIST_H

#include <stdlib.h>
#include <stdio.h>

struct eList
{
    int value;
    int pos;
    struct eList * next;
};

void eList_init(struct eList ** list)
{
    *list=NULL;
}

bool eList_preInsert(struct eList ** list, int val, int pos)
{
    struct eList * anello=(struct eList *)malloc(sizeof(struct eList));
    if(anello==NULL)
    {
        printf("ERRORE: Impossibile allocare memoria [%s:%d]", __FILE__, __LINE__);
        return false;
    }
    anello->value=val;
    anello->pos=pos;
    anello->next=(*list);
    *list=anello;
    return true;
}

bool eList_preRemove(struct eList ** list, int * val)
{
    if(*list==NULL)
    {
        printf("ERRORE: E' stato passato un puntatore nullo [%s:%d]",__FILE__,__LINE__);
        return false;
    }
    *val=(*list)->value;
    struct eList * anello=*list;
    *list=(*list)->next;
    free(anello);
    return true;
}

#endif //LISTEC_EXAMLIST_H
