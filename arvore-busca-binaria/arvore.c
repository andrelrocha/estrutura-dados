#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void faz_arvore_vazia(tipoNo* raiz) {
    *raiz = NULL;
}

void imprime_arvore(tipoNo raiz) {
    if (raiz != NULL) {
        imprime_arvore(raiz->esq);
        printf("%d ", raiz->chave);
        imprime_arvore(raiz->dir);
    }
}

void insere_no(tipoNo* raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(Celula));
        (*raiz)->chave = chave;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }

    if ((*raiz)->chave == chave) return NULL;

    if ((*raiz)->chave > chave) {
        insere_no(&(*raiz)->esq, chave);
    } else {
        insere_no(&(*raiz)->dir, chave);
    }
}

void remove_no(tipoNo* raiz, int chave) {
    if ((*raiz)->chave > chave) {
        remove_no(&(*raiz)->esq,chave);
    } else if ((*raiz)->chave < chave) {
        remove_no(&(*raiz)->dir,chave);
    } else {
        if ((*raiz)->esq == NULL) {
            tipoNo aux = *raiz;
            *raiz = (*raiz)-> dir;
            free(aux);
        } else if ((*raiz)->dir == NULL) {
            tipoNo aux = *raiz;
            *raiz = (*raiz)-> esq;
            free(aux);
        } else {
            tipoNo aux = (*raiz)->dir;
            while(aux->esq != NULL) {
                aux = aux->esq;
            }

             // Copia a chave do sucessor para o nó a ser removido
            (*raiz)->chave = aux->chave;
            // Remove o sucessor
            remove_no(&(*raiz)->dir, aux->chave);
        }
    }
}
