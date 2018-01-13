//
// Created by matteo.simonetti1@stud.unifi.it on 28/12/2017.
//

#ifndef LISTEC_SCUTILS_H
#define LISTEC_SCUTILS_H

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

bool isEqual(float a,float b)
{
    float diff, max;
    diff = fabs(a-b);
    a = fabs(a);
    b = fabs(b);
    max = a > b ? a : b;
    return ( diff < FLT_EPSILON*max );
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

bool generateRandomVectori(int * v, int n)
{
    if(v==NULL)
        return false;
    int i;
    for(i=0;i<n;i++)
    {
        v[i]=(rand()%100);
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

void printArrayi(int * v, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%d",v[i]);
    }
}

bool generateFibonacci(int ** v, int n)
{
    *v=(int *)malloc(sizeof(int)*n);
    if(*v==NULL)
    {
        printf("ERRORE: Impossibile generare il vettore di Fibonacci(%d) (%s:%d)",n,__FILE__,__LINE__);
        return false;
    }
    (*v)[0]=1;
    (*v)[1]=2;
    int i;
    for(i=2;i<n;i++)
    {
        (*v)[i]=(*v)[i-1]+(*v)[i-2];
    }
    return true;
}

bool iSearch(int * v, int n, int val)
{
    int i;
    bool found=false;
    for(i=0;i<n && !found;i++)
    {
        if(v[i]==val)
            found=true;
    }
    return found;
}

void revert(int * v, int n)
{
    int i;
    for(i=0;i<n/2;i++)
    {
        swapi(&(v[i]),&(v[n-i-1]));
    }
}

#endif //LISTEC_SCUTILS_H
