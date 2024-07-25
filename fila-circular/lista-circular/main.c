#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int desenfileira2(TipoFila* fila) {
    if (fila->tamanho == 1 || fila->tamanho == 0) {
        return 0;
    }

    Celula* topo = fila->cabeca;
    Celula* aux = topo;

    while (aux->prox != topo) {
        aux = aux->prox;
    }

    fila->cabeca = topo->prox;
    aux->prox = fila->cabeca;

    free(topo);
    fila->tamanho--;
    return 1;
}

int main()
{
    TipoFila fila;
    fazFilaVazia(&fila);

    /*
    imprimeFila(&fila);

    enfileira(&fila, 5);
    imprimeFila(&fila);


    enfileira(&fila, 10);
    imprimeFila(&fila);
    enfileira(&fila, 20);
    imprimeFila(&fila);

    desenfileira(&fila);
    imprimeFila(&fila);
    */

    adicionaFilaSimples(&fila, 10);
    adicionaFilaSimples(&fila, 20);
    adicionaFilaSimples(&fila, 30);
    imprimeFila(&fila);

    return 0;
}
