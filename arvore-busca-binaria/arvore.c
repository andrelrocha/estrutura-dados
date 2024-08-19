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
        if (*raiz == NULL) {
            fprintf(stderr, "Erro ao alocar memória.\n");
            exit(1);
        }
        (*raiz)->chave = chave;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else if ((*raiz)->chave > chave) {
        insere_no(&(*raiz)->esq, chave);
    } else if ((*raiz)->chave < chave) {
        insere_no(&(*raiz)->dir, chave);
    }
}
