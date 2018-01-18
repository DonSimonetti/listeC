//
// Created by Matteo Simonetti on 14/01/18.
//

#ifndef LISTEC_EXAMREMOVEFIB_H
#define LISTEC_EXAMREMOVEFIB_H

#include <stdbool.h>
#include <stdlib.h>
#include "scutils.h"
#include "examList.h"

bool removeFib(struct eList ** l, int ** v)
{
    printf("\n(%p)removeFib(%p,%p)",&removeFib,l,v);
    int size=eList_size(*l);
    //Generazione vettore di Fibonacci
    int * fib;
    if(!generateFibonacci(&fib,size))
        return false;
    //printArrayi(fib,size);
    //Fine generazione vettore di Fibonacci

    *v=(int *)malloc(size* sizeof(int));
    if(*v==NULL)
    {
        printf("ERRORE: Impossibile allocare memoria [%s:%d]",__FILE__,__LINE__);
        return false;
    }

    int i=0;
    struct eList ** iL;
    iL=l;
    //FIXED
    int oldVal;
    while((*iL)!=NULL && i<size)
    {
        //if(iSearch(*v,size,(*l)->pos)) //lascia stare, è meglio...
        if((*iL)->pos == fib[i])//il problema è qui dentro
        {
            eList_preRemove(iL,&oldVal);
            (*v)[i]=oldVal;
            //stack(*v,size,oldVal);//con questa funzione la complessità dell'intero algoritmo sarebbe stata quadratica
            i++;
        }
        else
            iL=&((*iL)->next);
    }
    //to here
    revert(*v,i);
    return true;
}

#endif //LISTEC_EXAMREMOVEFIB_H
