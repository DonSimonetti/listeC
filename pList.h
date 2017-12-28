//
// Created by Matteo Simonetti on 28/12/17.
//

#ifndef LISTEC_PLIST_H
#define LISTEC_PLIST_H

#include <stdbool.h>
#include <stdlib.h>

struct pList
{
    float value;
    struct pList * next;
};

void pList_init(struct pList ** list)
{
    *list= nullptr;
}

void pList_preInsert(struct pList ** list, float val)
{
    struct pList * tmp;
    tmp=*list;
    *list=(struct pList *)malloc(sizeof(struct pList));
    (*list)->next= tmp;
    (*list)->value=val;

}

#endif //LISTEC_PLIST_H
