#include <stdlib.h>
#include <stdio.h>
#include "maxheap.h"

int main() {
    // Cria um max-heap com capacidade para 10 elementos
    MaxHeap *heap = createMaxHeap(10);
    if (heap == NULL) {
        printf("Erro ao criar o heap.\n");
        return 1;
    }

    // Insere alguns elementos no heap
    insertMaxHeap(heap, 10);
    insertMaxHeap(heap, 20);
    insertMaxHeap(heap, 30);
    insertMaxHeap(heap, 5);
    insertMaxHeap(heap, 6);
    insertMaxHeap(heap, 1);

    // Imprime o heap após inserções
    printf("Heap apos insercoes:\n");
    printMaxHeap(heap);

    // Extrai o maior elemento
    int max = extractMax(heap);
    printf("Elemento extraido: %d\n", max);

    // Imprime o heap após extração
    printf("Heap apos extracao do maximo:\n");
    printMaxHeap(heap);

    // Libera a memoria alocada
    destroyMaxHeap(heap);

    return 0;
}
