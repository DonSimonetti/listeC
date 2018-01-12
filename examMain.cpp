//
// Created by matts on 29/12/2017.
//
#define NOMEALGORITMO "removeFib"
#include <stdio.h>
#include "scutils.h"
#include "examList.h"

void generaLista(struct eList ** list, int size);
void creaLista(struct eList ** list);

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

    switch (opzione)
    {
        case 1:{
            generaLista(&lista,size);
            break;
        }
        case 2:{
            creaLista(&lista);
            break;
        }
    }

    printf("\nOra verra' applicato il seguente algoritmo alla lista: "NOMEALGORITMO);
    return 0;
}

void generaLista(struct eList ** list, int size)
{
    printf("\nGenerazione della lista in corso..");
    *list=NULL;
    /*ROBE*/
    printf(" Lista generata con successo -> %p",*list);
}

void creaLista(struct eList ** list)
{
    int size,i;
    do
    {
        printf("\nDigitare il numero di elementi da aggiungere nella lista");
        i=scanf("%d",&size);
        if(i<=0 || size<=0)
            printf("\nHai digitato un valore non valido. Il numero di elementi deve essere superiore di 0 (size: %d , res: %d) [%s:%d]",size,i,__FILE__,__LINE__);

    }while(i<=0 || size<=0);
    printf("\nLa lista avra' %d elementi\nDigitare ora gli elementi (non sono ammessi valori con la virgola)",size);
    *list= NULL;
    int val;
    bool res=true;
    for(i=0;i<size && res==true;i++)
    {
        printf("\nElemento %d:",i+1);
        scanf("%d",&val);
        res=eList_preInsert(list,val,i);
    }
    if(!res)
    {
        printf("\nQualcosa è andato storto durante l'immissione dei valori [%s:%d]",__FILE__,__LINE__);
        return;
    }
    printf(" Lista generata con successo -> %p",*list);
}

