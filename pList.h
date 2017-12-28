//
// Created by Matteo Simonetti on 28/12/17.
//

#ifndef LISTEC_PLIST_H
#define LISTEC_PLIST_H

#include <stdbool.h>

struct pList
{
    float val;
    struct pList * next;
};

#endif //LISTEC_PLIST_H
