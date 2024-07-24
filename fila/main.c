#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Lista lista;

    createVoidList(&lista);
    printList(&lista);

    addValueToQueue(&lista, 10);
    addValueToQueue(&lista, 20);
    addValueToQueue(&lista, 30);

    printList(&lista);

    removeValueInQueue(&lista);

    printList(&lista);

    return 0;
}
