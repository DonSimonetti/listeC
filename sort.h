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
    bool swap_found=false;
    int i,j=0;
    do
    {
        for(i=0;i<n-j-1;i++)
        {
            if(v[i]>v[i+1])
            {
                swapf(&(v[i]), &(v[i + 1]));
                swap_found = true;
            }
        }
        j++;
    }
    while (!swap_found);
}

bool merge();

bool _mergeSort();

bool mergeSort();

bool quickSort();

#endif //LISTEC_SORT_H
