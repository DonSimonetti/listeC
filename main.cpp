#include <stdlib.h>
#include "pList.h"

int main() 
{
    struct pList * lista1;
    pList_generate(&lista1,9);
    pList_visit(lista1);
    return 0;
}