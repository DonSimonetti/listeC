//
// Created by matteo.simonetti1@stud.unifi.it on 29/12/17.
//

#ifndef LISTEC_RESEARCH_H
#define LISTEC_RESEARCH_H

#include <stdbool.h>
#include "scutils.h"

bool binSearch(float * v, int n, float target)
{
    if(n>0)//array non vuota
    {
        if(isEqual(v[n/2],target))
            return true;
        else
        {
            if(v[n/2]>target)
                return binSearch(v,n/2,target);
            else
                return binSearch(&(v[n/2+1]),n/2-1,target);
        }
    }
}

bool search(float * v, int n, float target)
{
    int i;
    bool found=false;
    for(i=0;i<n && !found;i++)
    {
        if(isEqual(v[i],target))
            found=true;
    }
    return found;
}

#endif //LISTEC_RESEARCH_H
