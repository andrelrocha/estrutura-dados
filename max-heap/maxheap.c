#include <stdlib.h>
#include <stdio.h>
#include "maxheap.h"

int verifyHeapIsEmpty(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap esta vazio.\n");
        return 0;
    }
}

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));

    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

void destroyMaxHeap(MaxHeap *heap) {
    free(heap->data);
    free(heap);
}

int getMax(MaxHeap *heap) {
    if (verifyHeapIsEmpty(heap) == 0) return 0;
    return heap->data[0];
}

int extractMax(MaxHeap *heap) {
    if (verifyHeapIsEmpty(heap) == 0) return 0;

    int max = heap->data[0];
    heap->data[0] = heap->data[--(heap->size)]; //passa o último elemento do array para o início

    maxHeapify(heap, 0);

    return max;
}

void maxHeapify(MaxHeap *heap, int i) {
    int largest = i;        // Inicializa o maior como raiz
    int left = 2 * i + 1;   // Filho esquerdo
    int right = 2 * i + 2;  // Filho direito

    // Se o filho esquerdo for maior que a raiz
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }

    // Se o filho direito for maior que o maior até agora
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }

    // Se o maior não for a raiz
    if (largest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;

        // Recursivamente faz o heapify no subárvore afetado
        maxHeapify(heap, largest);
    }
}

void insertMaxHeap(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap esta cheio.\n");
        return;
    }

    int i = heap->size++;
    heap->data[i] = value;

    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}


void printMaxHeap(MaxHeap *heap) {
    printf("MaxHeap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}
