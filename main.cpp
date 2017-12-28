#include <stdlib.h>
#include "pList.h"

int main() 
{
    struct pList * lista1;
    pList_generate(&lista1,9);
    pList_ordInsert(&lista1,3.142);
    pList_ordInsert(&lista1,2);
    pList_visit(lista1);
    return 0;
}