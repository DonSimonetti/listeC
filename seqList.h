//
// Created by Matteo Simonetti on 28/12/17.
//

#ifndef LISTEC_SEQLIST_H
#define LISTEC_SEQLIST_H

struct seqList
{
    float * buffer;
    int head;
    int tail;
    int size;
};

void seqList_init(struct seqList * list,int size)
{

}

#endif //LISTEC_SEQLIST_H
