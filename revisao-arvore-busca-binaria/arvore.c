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
