#include <stdlib.h>
#include "pList.h"
#include "seqList.h"

int main() 
{
    printf("\nlista collegata con puntatori..");
    struct pList * lista1;
    pList_generate(&lista1,9);
    pList_ordInsert(&lista1,3.142);
    pList_ordInsert(&lista1,2);
    pList_visit(lista1);
    printf("\nlista sequenziale..");
    struct seqList lista2;
    seqList_generate(&lista2,9,5);
    seqList_visit(&lista2);
    return 0;
}