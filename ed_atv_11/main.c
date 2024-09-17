#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

// Fun��o para preencher o array com valores aleat�rios
void preencherArray(int A[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        A[i] = rand() % (tamanho * 10); // Gera n�meros aleat�rios
    }
}

int main() {
    int tamanhos[] = {500, 5000, 10000, 30000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Array para armazenar as m�tricas de cada tamanho
    Metricas metricasHeap[numTamanhos];
    Metricas metricasQuick[numTamanhos];
    Metricas metricasMerge[numTamanhos];

    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios

    for (int i = 0; i < numTamanhos; i++) {
        int tamanho = tamanhos[i];
        int* array = (int*) malloc(tamanho * sizeof(int));

        // Heapsort
        preencherArray(array, tamanho);
        metricasHeap[i].comparacoes = 0;
        metricasHeap[i].movimentacoes = 0;
        heapsort(array, tamanho, &metricasHeap[i]);

        // Quicksort
        preencherArray(array, tamanho);
        metricasQuick[i].comparacoes = 0;
        metricasQuick[i].movimentacoes = 0;
        quicksort(array, 0, tamanho - 1, &metricasQuick[i]);

        // Mergesort
        preencherArray(array, tamanho);
        metricasMerge[i].comparacoes = 0;
        metricasMerge[i].movimentacoes = 0;
        mergesort(array, 0, tamanho - 1, &metricasMerge[i]);

        free(array); // Libera a mem�ria alocada
    }

    // Chama a fun��o para imprimir a tabela com as compara��es
    imprimirTabela(tamanhos, metricasHeap, metricasQuick, metricasMerge, numTamanhos);

    return 0;
}
