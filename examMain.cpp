//
// Created by matts on 29/12/2017.
//
#define NOMEALGORITMO "removeFib"
#include <stdio.h>
#include "scutils.h"
#include "examList.h"
#include "examRemoveFib.h"

bool generaLista(struct eList ** list, int size);
bool creaLista(struct eList ** list, int size);
bool removeFib(struct eList ** l, int ** v);

int main()
{
    printf("Bisogna creare una lista: scegli un opzione digitando il numero seguito da INVIO:\n");
    printf("1) La lista verra' generata automaticamente a caso\n2) La lista verra' creata manualmente\n");

    int opzione;
    do {
        scanf("%d", &opzione);
        if (!(opzione==1 || opzione==2))
            printf("ERRORE: L'opzione %d non e' valida. Digitare 1 o 2\n",opzione);
    }
    while (!(opzione==1 || opzione==2));

    printf("\nHai selezionato l'opzione %d",opzione);
    printf("\nSpecificare ora la grandezza della lista");

    int size;
    do{
        printf("\n");
        scanf("%d",&size);
        if(size<=0)
            printf("\nERRORE: La grandezza della lista non e' valida. Digitare un numero strettamente maggiore di 0");
    }while(size<=0);

    printf("\nLa grandezza della lista sara' %d",size);

    struct eList * lista;
    bool res;

    switch (opzione)
    {
        case 1:{
            res=generaLista(&lista,size);
            break;
        }
        case 2:{
            res=creaLista(&lista,size);
            break;
        }
    }

    if(res)
    {
        eList_print(lista);

        printf("\n");

        printf("\nOra verra' applicato il seguente algoritmo alla lista: removeFib");

        int * oldElems;

        bool res=removeFib(&lista,&oldElems);

        if(!res)
        {
            printf("\nERRORE: Qualcosa è andato storto nell'algoritmo [%s:%d]",__FILE__,__LINE__);
            return 1;
        }
        printf("\nStampa della lista dopo removeFib:");
        eList_print(lista);

        printArrayi(oldElems,size);

        free(oldElems);
        printf("\nFINE");
    }
    else
        printf("\nERRORE: La creazione/generazione della lista è terminata senza successo");






    free(lista);
    return 0;
}

bool generaLista(struct eList ** list, int size)
{
    printf("\nGenerazione della lista in corso..");
    eList_init(list);
    int i;
    bool res= true;

    for(i=0;i<size && res==true;i++)
        res=eList_sufInsert(list,rand()%200,i+1);

    if(!res)
    {
        printf("\nQualcosa è andato storto durante la generazione dei valori [%s:%d]",__FILE__,__LINE__);
        return false;
    }
    printf(" Lista generata con successo -> %p",*list);
    return true;
}

bool creaLista(struct eList ** list, int size)
{
    printf("\nCreazione della lista:\nDigitare ora gli elementi (non sono ammessi valori con la virgola)");
    eList_init(list);
    int val,i;
    bool res=true;
    for(i=0;i<size && res==true;i++)
    {
        printf("\nElemento %d:",i+1);
        scanf("%d",&val);
        res=eList_sufInsert(list,val,i+1);
    }
    if(!res)
    {
        printf("\nQualcosa e' andato storto durante l'immissione dei valori [%s:%d]",__FILE__,__LINE__);
        return false;
    }
    printf(" Lista creata con successo -> %p",*list);
    return true;
}

