#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

void criaFP(TipoFP *fp) {
    *fp = NULL;
}


void apagaNode(TipoFP fp) {
    if (fp != NULL) {
        apagaNode(fp->esq);
        apagaNode(fp->dir);
        free(fp);
    }
}
void apagaFP(TipoFP *fp) {
    apagaNode(*fp);
    *fp = NULL;
}

void imprimeFP(TipoFP fp) {
    if (fp != NULL) {
        imprimeFP(fp->dir);
        printf("%d ", fp->registro);
        imprimeFP(fp->esq);
    }
}

void insereFP(int x, TipoFP *fp) {
    if ((*fp) == NULL) {
        *fp = (TipoFP)malloc(sizeof(TipoNo));
        (*fp)->registro = x;
        (*fp)->esq = NULL;
        (*fp)->dir = NULL;
    }

    if (x < (*fp)->registro) {
        insereFP(x, &(*fp)->esq);
    } else if (x > (*fp)->registro) {
        insereFP(x, &(*fp)->dir);
    } else {
        return;
    }
}

void retiramax(int *x, TipoFP *fp) {
    if ((*fp) == NULL) return;

    if ((*fp)->dir != NULL) {
        retiramax(x, &(*fp)->dir);
    } else {
        *x = (*fp)->registro;
        TipoFP temp = *fp;
        *fp = (*fp)->esq;
        free(temp);
    }
}

void retiraNo(int x, TipoFP *fp) {
    if (*fp == NULL) return;

    if (x < (*fp)->registro) {
        retiraNo(x, &(*fp)->esq);
    } else if (x > (*fp)->registro) {
        retiraNo(x, &(*fp)->dir);
    } else {
        if ((*fp)->esq == NULL) {
            TipoFP aux = *fp;
            *fp = (*fp)->dir;
            free(aux);
        } else if ((*fp)->dir == NULL) {
            TipoFP aux = *fp;
            *fp = (*fp)->esq;
            free(aux);
        } else {
            TipoFP aux = (*fp)->dir;
            while (aux->esq != NULL) {
                aux = aux->esq;
            }
            (*fp)->registro = aux->registro;
            retiraNo(aux->registro, &(*fp)->dir);
        }
    }
}

TipoFP searchItem(int x, TipoFP *fp) {
    if (*fp == NULL) return fp;

    if (x == (*fp)->registro) return fp;

    TipoFP aux = searchItem(x, &(*fp)->esq);
    if (aux) return aux;
    return searchItem(x, &(*fp)->dir);
}
