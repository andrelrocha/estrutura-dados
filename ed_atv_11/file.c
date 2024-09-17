#include <stdlib.h>
#include <stdio.h>
#include "file.h"

// Heapsort
void heapsort(int A[], int n, Metricas* m) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i, m);
    }

    // Extrai os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Movimentação: troca o elemento da raiz com o último elemento
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        m->movimentacoes += 3; // 3 movimentações (swap)

        // Heapify na raiz para restaurar a propriedade do heap
        heapify(A, i, 0, m);
    }
}

void heapify(int A[], int n, int i, Metricas* m) {
    int maior = i;       // Inicializa o maior como raiz
    int esq = 2 * i + 1; // Filho esquerdo
    int dir = 2 * i + 2; // Filho direito

    // Se o filho esquerdo for maior que a raiz
    m->comparacoes++;
    if (esq < n && A[esq] > A[maior]) {
        maior = esq;
    }

    // Se o filho direito for maior que o maior até agora
    m->comparacoes++;
    if (dir < n && A[dir] > A[maior]) {
        maior = dir;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        // Movimentação: troca o elemento da raiz com o maior
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        m->movimentacoes += 3; // 3 movimentações (swap)

        // Recursivamente heapify o subárvore afetada
        heapify(A, n, maior, m);
    }
}

// Quicksort
void quicksort(int A[], int inicio, int fim, Metricas* m) {
    if (inicio < fim) {
        int pivo = particiona(A, inicio, fim, m);
        quicksort(A, inicio, pivo - 1, m);
        quicksort(A, pivo + 1, fim, m);
    }
}


int particiona(int A[], int inicio, int fim, Metricas* m) {
    int pivo = A[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        m->comparacoes++;
        if (A[j] <= pivo) {
            i++;
            // Movimentação
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            m->movimentacoes += 3; // 3 movimentações (swap)
        }
    }
    // Movimentação
    int temp = A[i + 1];
    A[i + 1] = A[fim];
    A[fim] = temp;
    m->movimentacoes += 3; // 3 movimentações (swap)

    return i + 1;
}

// Mergesort
void mergesort(int A[], int inicio, int fim, Metricas* m) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergesort(A, inicio, meio, m);
        mergesort(A, meio + 1, fim, m);
        merge(A, inicio, meio, fim, m);
    }
}

void merge(int A[], int inicio, int meio, int fim, Metricas* m) {
    int n = fim - inicio + 1;
    int temp[n];

    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        m->comparacoes++;
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
        m->movimentacoes++;
    }

    while (i <= meio) {
        temp[k++] = A[i++];
        m->movimentacoes++;
    }

    while (j <= fim) {
        temp[k++] = A[j++];
        m->movimentacoes++;
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        A[i] = temp[k];
    }
}

// Função para imprimir a tabela
void imprimirTabela(int tamanhos[], Metricas h_metrics[], Metricas q_metrics[], Metricas m_metrics[], int numTamanhos) {
    printf("+--------------------------------------------------------------+\n");
    printf("| Metodo        500   5000   10000   30000  |\n");

    // Imprimindo os resultados de Heapsort
    printf("| Heapsort      ");
    for (int i = 0; i < numTamanhos; i++) {
        printf("%d   ", h_metrics[i].comparacoes);
    }
    printf("|\n");

    // Imprimindo os resultados de Quicksort
    printf("| Quicksort     ");
    for (int i = 0; i < numTamanhos; i++) {
        printf("%d   ", q_metrics[i].comparacoes);
    }
    printf("|\n");

    // Imprimindo os resultados de Mergesort
    printf("| Mergesort     ");
    for (int i = 0; i < numTamanhos; i++) {
        printf("%d   ", m_metrics[i].comparacoes);
    }
    printf("|\n");

    printf("+--------------------------------------------------------------+\n");
}


