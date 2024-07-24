#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Lista lista;

    createVoidList(&lista);
    printList(&lista);

    addElementToStack(10, &lista);
    addElementToStack(20, &lista);
    addElementToStack(30, &lista);
    addElementToStack(15, &lista);

    printList(&lista);

    removeElementInStack(&lista);

    printList(&lista);
    return 0;
}
