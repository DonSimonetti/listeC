//
// Created by matts on 30/12/2017.
//

#ifndef LISTEC_SORT_H
#define LISTEC_SORT_H

#include <stdbool.h>
#include "scutils.h"

void selectionSort(float * v, int n)//Si trova il massimo e si fa lo swap
{
    if(n>0)
    {
        int i, iMax;
        //trovo indice del valore massimo
        for (i = 0, iMax = 0; i < n; i++)
        {
            if (v[i] > v[iMax])
                iMax = i;
        }
        //faccio swap
        swapf(&(v[iMax]), &(v[n - 1]));

        selectionSort(v,n-1);
    }
}

void bubbleSort(float * v, int n)//confronto ogni elemento col suo successivo, se è più grande faccio lo swap
{
    if(n==1)
        return;
    int i;
    bool swap_found;
    for(i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            swapf(&(v[i]), &(v[i + 1]));
            swap_found = true;
        }
    }
    bubbleSort(v,n-1);
}
//da qui in poi uso valori int per semplicità
void merge(int * v, int n, int n1, int * tmp2)//Completato
{
    int l;
    for(l=0;l<n1;l++)
        tmp2[l]=v[l];
    int i,r;
    l=0;
    r=0;
    for(i=0,l=0,r=0;i<n && l<n1 && r<n-n1;i++)
    {
        if(tmp2[l]>v[n1+r])
        {
            v[i]=v[n1+r];
            r++;
        }
        else
        {
            v[i]=tmp2[l];
            l++;
        }
    }
    for(;l<n1;l++)
    {
        v[l+r]=tmp2[l];
    }
}

void _mergeSort(int * v, int n, int * tmp)
{
    if(n>2)
    {
        _mergeSort(v,n/2,tmp);//semivettore sinistro
        _mergeSort(&(v[n/2]),n-n/2,&(tmp[n/2]));//semivettore destro
        merge(v,n,n/2,tmp);
    }
    else if(n==2)
        if(v[0]>v[1])
            swapi(&(v[0]),&(v[1]));
}

bool mergeSort(int * v, int n)
{
    int * tmp;
    tmp=(int *)malloc(n/2* sizeof(int));
    if(tmp==NULL)
        return false;
    _mergeSort(v,n,tmp);
    free(tmp);
    return true;
}

int qsPartition(int * v,int n)
{
    int pivot=v[0];
    int l=0;
    int r=n;

    while(l<r)
    {
        while(r>l && v[r]>pivot)
            r--;
        if(r!=l)
        {
            while(l<r && v[l]<=pivot)
                l++;
            swapi(&(v[l]),&(v[r]));
        }
    }
    swapi(&(v[0]),&(v[l]));
    return l+1;
}

void quickSort(int * v, int n)
{
    if(n>0)
    {
        int q=qsPartition(v,n);
        quickSort(v,q-1);
        quickSort(&(v[q]),n-q);
    }
}



#endif //LISTEC_SORT_H
