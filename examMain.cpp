//
// Created by matts on 29/12/2017.
//
#define NOMEALGORITMO "nomealgorimo"
#include <stdio.h>
#include "scutils.h"
#include <examList.h>

void generaLista(int size);
void creaLista(int size);

int main()
{
    printf("Bisogna creare una lista: scegli un opzione digitando il numero seguito da INVIO:\n");
    printf("1) La lista verra' generata automaticamente a caso\n2) La lista verra' creata manualmente\n");

    short opzione;
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

    switch (opzione)
    {
        case 1:{
            generaLista(size);
            break;
        }
        case 2:{
            creaLista(size);
            break;
        }
    }

    printf("\nOra verra' applicato il seguente algoritmo alla lista: "NOMEALGORITMO);
    return 0;
}

void generaLista(int size)
{
    printf("\nGenerazione della lista in corso..");
    /*ROBE*/
    printf(" Lista generata con successo");
}

void creaLista(int size)
{

}

