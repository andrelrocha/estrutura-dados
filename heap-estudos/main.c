#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

int main()
{
    TipoHeap heap;

    fazHeapVazio(&heap);

    insereHeap(&heap, 10);
    insereHeap(&heap, 20);
    insereHeap(&heap, 5);
    insereHeap(&heap, 30);
    insereHeap(&heap, 15);
    insereHeap(&heap, 8);
    insereHeap(&heap, 12);

    printf("Heap apos insercoes:\n");
    imprimeHeap(&heap);

    printf("Removendo o maximo (raiz):\n");
    retiraMax(&heap);
    imprimeHeap(&heap);

    printf("Removendo o maximo (raiz):\n");
    retiraMax(&heap);
    imprimeHeap(&heap);

    return 0;
}
