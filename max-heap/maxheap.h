#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdbool.h>

typedef struct {
    int *data;      // Ponteiro para o array que representa o heap
    int size;       // Número de elementos no heap
    int capacity;   // Capacidade máxima do heap
} MaxHeap;


// Função para criar um MaxHeap
MaxHeap* createMaxHeap(int capacity);

// Função para liberar a memória alocada para o MaxHeap
void destroyMaxHeap(MaxHeap *heap);

// Função para obter o maior valor (raiz) do MaxHeap
int getMax(MaxHeap *heap);

// Função para remover e retornar o maior valor do MaxHeap
int extractMax(MaxHeap *heap);

// Função para inserir um novo valor no MaxHeap
void insertMaxHeap(MaxHeap *heap, int value);

// Função para verificar se o MaxHeap está vazio
int verifyHeapIsEmpty(MaxHeap *heap);

// Função para fazer o heapify de um subárvore com raiz no índice i
void maxHeapify(MaxHeap *heap, int i);

// Função para imprimir o heap
void printMaxHeap(MaxHeap *heap);

#endif
