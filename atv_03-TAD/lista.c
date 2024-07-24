#include <stdlib.h>
#include "lista.h"


void fazListaVazia(TipoLista* lista) {
    lista->tamanho = 0;
    lista->primeiro = NULL;
}

int insereLista(TipoLista* lista, tipoChave chave) {
    Celula* p = malloc(sizeof(Celula));

    p->chave = chave;
    p->prox = lista->primeiro;

    lista->primeiro = p;
    lista->tamanho++;
    return 1;
}

int buscaRemoveDaLista(TipoLista* lista, tipoChave chave) {
    Celula* p = lista->primeiro;

    if (p->chave == chave) {
        Celula* q = p;
        lista->primeiro = p->prox;
        free(q);
        lista->tamanho--;
        return 1;
    }

    while (p->prox != NULL) {
        if (p->prox->chave == chave) {
            Celula* q = p->prox;
            p->prox = p->prox->prox;
            free(q);
            lista->tamanho--;
            return 1;
        }
        p = p->prox;
    }
    return 0;
}


