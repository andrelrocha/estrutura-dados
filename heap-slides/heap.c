#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "heap.h"

void desceEsqNoHeap(TipoIndice esq, TipoIndice dir, TipoItem *A) {
    TipoIndice i = esq;
    int j = i*2;

    TipoItem x = A[i];

    while (j <= dir) {
        if (j < dir && A[j].chave < A[j+1].chave) {
            j++;
        }

        if (x.chave >= A[j].chave) {
            break;
        }

        A[i] = A[j];
        i = j;
        j = i*2;
    }

    A[i] = x;
}

void constroi(TipoItem *A, TipoIndice n) {
    TipoIndice esq = n/2 + 1;

    while (esq > 1) {
        esq--;
        desceEsqNoHeap(esq, n, A);
    }
}

TipoItem retiraMax(TipoItem *A, TipoIndice *n) {
    TipoItem max;

    if (*n < 1) {
        printf("Erro: heap vazio.\n");
    } else {
        max = A[1];
        A[1] = A[*n];
        (*n)--;
        desceEsqNoHeap(1, *n, A);
    }

    return max;
}

void insereHeap(TipoItem *A, TipoItem novoItem, TipoIndice *n) {
    TipoIndice i = *n;

    (*n)++;

    A[i] = novoItem;

    while (i > 1 && A[i/2].chave < A[i].chave) {
        TipoItem aux = A[i];
        A[i] = A[i/2];
        A[i/2] = aux;
    }
}
