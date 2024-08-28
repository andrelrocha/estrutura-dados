#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdbool.h>

typedef struct {
    int *data;      // Ponteiro para o array que representa o heap
    int size;       // N�mero de elementos no heap
    int capacity;   // Capacidade m�xima do heap
} MaxHeap;


// Fun��o para criar um MaxHeap
MaxHeap* createMaxHeap(int capacity);

// Fun��o para liberar a mem�ria alocada para o MaxHeap
void destroyMaxHeap(MaxHeap *heap);

// Fun��o para obter o maior valor (raiz) do MaxHeap
int getMax(MaxHeap *heap);

// Fun��o para remover e retornar o maior valor do MaxHeap
int extractMax(MaxHeap *heap);

// Fun��o para inserir um novo valor no MaxHeap
void insertMaxHeap(MaxHeap *heap, int value);

// Fun��o para verificar se o MaxHeap est� vazio
int verifyHeapIsEmpty(MaxHeap *heap);

// Fun��o para fazer o heapify de um sub�rvore com raiz no �ndice i
void maxHeapify(MaxHeap *heap, int i);

// Fun��o para imprimir o heap
void printMaxHeap(MaxHeap *heap);

#endif
