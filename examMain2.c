//
// Created by Matteo Simonetti on 18/01/18.
//

#include <stdio.h>
#include <time.h>
#include <memory.h>
#include "scutils.h"
#include "examList.h"
#include "examRemoveFib.h"

bool generaLista(struct eList ** list, int size);
bool creaLista(struct eList ** list);

int main()
{
    unsigned int seed=time(NULL);
    srand(seed);
    printf("Bisogna creare una lista: scegli un opzione digitando il numero seguito da INVIO:\n");
    printf("1) La lista verra' generata automaticamente a caso\n2) La lista verra' creata manualmente\n");

    int opzione;
    do
    {
        scanf("%d", &opzione);
        if (!(opzione==1 || opzione==2))
            printf("ERRORE: L'opzione %d non e' valida. Digitare 1 o 2\n",opzione);
    }
    while (!(opzione==1 || opzione==2));

    printf("\nHai selezionato l'opzione %d",opzione);
    int size;
    if(opzione==1)
    {
        printf("\nSpecificare ora la grandezza della lista");

        do
        {
            printf("\n");
            scanf("%d", &size);
            if (size <= 0)
                printf("\nERRORE: La grandezza della lista non e' valida. Digitare un numero strettamente maggiore di 0");
        } while (size <= 0);
        printf("\nLa grandezza della lista sara' %d",size);
    }

    struct eList * lista;
    bool res;

    switch (opzione)
    {
        case 1:{
            res=generaLista(&lista,size);
            break;
        }
        case 2:{
            res=creaLista(&lista);
            size=eList_size(lista);
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
        free(lista);
        printf("\nFINE\n");
    }
    else
        printf("\nERRORE: La creazione/generazione della lista è terminata senza successo");
    return 0;
}

bool generaLista(struct eList ** list, int size)
{
    printf("\nGenerazione della lista in corso..");
    //eList_init(list);
    *list=NULL;//abbasso il costo computazionale
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

bool creaLista(struct eList ** list)
{
    printf("\nCreazione della lista:\nDigitare \"add [valore]\" per aggiungere elementi (non sono ammessi valori con la virgola)\nScrivere \"stop\" per terminare l'immissione di valori\n");
    eList_init(list);
    int i,val;
    bool res=true;
    bool stop=false;
    i=0;
    char cmd[16];
    do
    {
        printf("\n");
        scanf("%s %d",cmd,&val);
        if(!strcmp(cmd,"stop"))
            stop=true;
        else if(!strcmp(cmd,"add"))
        {
            i++;
            printf("Elemento %d: %d",i,val);
            res = eList_sufInsert(list, val, i);
        }
        else
            printf("ERRORE: comando non riconosciuto [%s:%d]\n",__FILE__,__LINE__);

    }while(res==true && !stop);

    if(!res)
    {
        printf("\nQualcosa e' andato storto durante l'immissione dei valori [%s:%d]",__FILE__,__LINE__);
        return false;
    }
    printf(" Lista creata con successo -> %p",*list);
    return true;
}