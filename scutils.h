//
// Created by matts on 28/12/2017.
//

#ifndef LISTEC_SCUTILS_H
#define LISTEC_SCUTILS_H

#include <stdbool.h>
#include <math.h>

bool isEqual(float a, float b)
{
    return fabsf(a-b)<FLT_EPSILON;
}

void swapf(float * a, float * b)
{
    float tmp=*a;
    *a=*b;
    *b=tmp;
}

void swapi(int * a, int * b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

#endif //LISTEC_SCUTILS_H
