#ifndef TAD_H
#define TAD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int comparacoes;
    int movimentacoes;
} Metricas;

// Prototipos das funções de ordenação
void heapsort(int A[], int n, Metricas* m);
void quicksort(int A[], int inicio, int fim, Metricas* m);
void mergesort(int A[], int inicio, int fim, Metricas* m);
void merge(int A[], int inicio, int meio, int fim, Metricas* m);

// Funções auxiliares
void gerarArrayAleatorio(int A[], int n);
void imprimirTabela(int tamanhos[], Metricas* h_metrics, Metricas* q_metrics, Metricas* m_metrics, int numTamanhos);

#endif

