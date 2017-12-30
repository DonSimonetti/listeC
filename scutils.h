//
// Created by matts on 28/12/2017.
//

#ifndef LISTEC_SCUTILS_H
#define LISTEC_SCUTILS_H

#include <stdbool.h>
#include <stdlib.h>
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

bool generateRandomVectorf(float * v, int n)
{
    if(v==NULL)
        return false;
    int i;
    for(i=0;i<n;i++)
    {
        v[i]=(float)(rand()%100);
    }
    return true;
}

void printArrayf(float * v, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%.3f",v[i]);
    }
}

#endif //LISTEC_SCUTILS_H
