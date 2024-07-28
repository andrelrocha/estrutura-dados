#include "pilha.h"
#include <stdlib.h>

void faz_pilha_vazia(TipoPilha* pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int empilha(TipoPilha* pilha, tipoElemento* elemento) {
    Celula* node = malloc(sizeof(Celula));
    node->chave = elemento;

    if (pilha->tamanho == 0) {
        node->prox = NULL;
    } else {
        node->prox = pilha-> topo;
    }

    pilha->topo = node;
    pilha->tamanho++;

    return 1;
}
int desempilha(TipoPilha* pilha, tipoElemento* elemento) {
    if (pilha->topo == NULL) {
        return 0;
    }

    Celula* aux = pilha->topo;

    pilha->topo=aux->prox;
    free(aux);
    pilha->tamanho--;
    return 1;
}

void imprime_pilha(TipoPilha* pilha) {
    Celula* aux = pilha->topo;
    if (aux == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    while (aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int tamanho_pilha(TipoPilha* pilha) {
    return pilha->tamanho;
}
