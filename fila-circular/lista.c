#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void fazFilaVazia(TipoFila* fila) {
    fila->cabeca = NULL;
    fila->tamanho = 0;
}

void imprimeFila(TipoFila* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia\n");
        return;
    }

    Celula* atual = fila->cabeca;
    do {
        printf("%d ", atual->elem);
        atual = atual->prox;
    } while (atual != fila->cabeca);

    printf("\n");
}


int enfileira(TipoFila* fila, tipoElemento* elem) {
    Celula* node = malloc(sizeof(Celula));

    node->elem = elem;
    node->prox = NULL;

    if (fila->tamanho == 0) {
        fila->cabeca = node;
        node->prox = node;
        fila->tamanho++;
        return 1;
    }

    Celula* topo = fila->cabeca;
    Celula* aux = topo;

    while (aux->prox != topo) {
        aux = aux->prox;
    }

    aux-> prox = node;
    node-> prox = topo;
    fila->tamanho++;
    return 0;
}

int adicionaFilaSimples(TipoFila* fila, tipoElemento* elem) {
    Celula* node = malloc(sizeof(Celula));
    node->elem =  elem;
    node->prox = NULL;
    if (fila->tamanho == 0) {
        fila->cabeca = node;
        fila->tamanho++;
        return 1;
    }

    Celula* aux = fila->cabeca;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = node;
    fila->tamanho++;
    return 1;
}

int desenfileira(TipoFila* fila) {
    if (fila->tamanho == 1 || fila->tamanho == 0) {
        fazFilaVazia(fila);
        return 0;
    }

    Celula* oldCabeca = fila->cabeca;
    Celula* aux = oldCabeca;

    while (aux->prox != oldCabeca) {
        aux = aux->prox;
    }

    fila->cabeca = oldCabeca->prox;
    aux->prox = fila->cabeca;

    free(oldCabeca);
    fila->tamanho--;
    return 1;
}

int desenfileraSimples(TipoFila* fila) {
    if (fila->tamanho == 1 || fila->tamanho == 0) {
        fazFilaVazia(fila);
        return 0;
    }

    Celula* aux = fila->cabeca;

    fila->topo = aux->prox;
    free(aux);
    return 1;
}