#include <stdio.h>
#include "teste.h"

void imprimeTeste(int x) {
    printf("Header funcionando com numero %d.\n", x);
}

void fazHeapVazio(TipoHeap *heap) {
    heap->n = 0;
}

int heapVazio(TipoHeap *heap) {
    return heap->n == 0;
}

void insereHeap(TipoHeap *heap, int chave) {
    TipoIndice i = heap->n;

    if (heap->n >= MAXTAM) {
        printf("Fila de prioridade cheia!\n");
        return;
    }

    heap->itens[i] = chave;
    heap->n++;

    while (i > 0 && heap->itens[(i-1)/2] < heap->itens[i]) {
        int aux = heap->itens[(i-1)/2];
        heap->itens[(i-1)/2] = heap->itens[i];
        heap->itens[i] = aux;

        i = (i-1) / 2;
    }
}

void desceNoHeap(TipoHeap *heap, TipoIndice i) {
    TipoIndice maior = i;
    TipoIndice esquerda = 2 * i + 1;
    TipoIndice direita = 2 * i + 2;

    // Verifica se o filho esquerdo existe e é maior que o nó atual
    if (esquerda < heap->n && heap->itens[esquerda] > heap->itens[maior]) {
        maior = esquerda;
    }

    // Verifica se o filho direito existe e é maior que o nó atual ou o filho esquerdo
    if (direita < heap->n && heap->itens[direita] > heap->itens[maior]) {
        maior = direita;
    }

    // Se o maior não é o nó atual, troca e desce o nó
    if (maior != i) {
        int aux = heap->itens[i];
        heap->itens[i] = heap->itens[maior];
        heap->itens[maior] = aux;

        // Chama recursivamente para garantir que o heap esteja correto
        desceNoHeap(heap, maior);
    }

}

void retiraMax(TipoHeap *heap) {
    if (heap->n == 0) {
        printf("Heap está vazio.\n");
        return;
    }

    // Substitui a raiz do heap (máximo) pelo último item
    heap->itens[0] = heap->itens[heap->n - 1];
    heap->n--;

    desceNoHeap(heap, 0);
}

void imprimeHeap(TipoHeap *heap) {
    if (heap->n == 0) {
        printf("Heap esta vazio.\n");
        return;
    }

    printf("Heap: ");
    for (int i = 0; i < heap->n; i++) {
        printf("%d ", heap->itens[i]);
    }
    printf("\n");
}
