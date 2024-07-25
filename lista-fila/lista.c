#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void fazFilaVazia(TipoFila *fila) {
    fila->after = 0;
    fila->start = 0;
    fila->tam = 0;

    for (int i = 0; i < TAM; i++) {
        fila->elementos[i] = 0;
    }
}

int enfileira(TipoFila *fila, tipoElemento *elem) {
    fila->elementos[fila->start] = elem;
    fila->start = (fila->start + 1) % TAM;

    fila->tam++;
    return 1;
}

int desenfileira(TipoFila *fila) {
    fila->elementos[fila->after] = 0;
    fila->after = (fila->after + 1) % TAM;

    fila->tam--;
    return 1;
}

void imprimefila(TipoFila *fila) {
    if (fila->tam == 0) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");
    for (int i = 0; i < fila->tam; i++) {
        int idx = (fila->after + i) % TAM;
        printf("%d ", fila->elementos[idx]);
    }
    printf("\n");
}

int filaVazia(TipoFila *fila) {
    if (fila->tam == 0) {
        printf("Fila vazia.\n");
        return;
    }

    int aux = 0;

    for (int i = 0; i <TAM; i++) {
        if (fila->elementos[i] == 0) {
            continue;
        } else {
            aux++;
        }
    }

    if (aux == 0) {
        printf("Fila vazia !");
        return 0;
    } else {
        printf("Existem %d elementos na lista\n", aux);
        return 1;
    }
}

int filaCheia(TipoFila *fila) {
    if (fila->tam == 0) {
        printf("Fila vazia.\n");
        return;
    }

    int aux = 0;

    for (int i = 0; i <TAM; i++) {
        if (fila->elementos[i] == 0) {
            continue;
        } else {
            aux++;
        }
    }

    if (aux != TAM) {
        printf("Fila nao esta cheia !");
        return 0;
    } else {
        printf("Fila está cheia");
        return 1;
    }
}
