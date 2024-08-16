#include <stdlib.h>
#include <stdio.h>
#include "TipoFP.h"
#include "TipoFilaFIFO.h"

void criaFP(TipoFP *fp) {
    *fp = NULL;
}

void apagaNo(TipoApontador no) {
    if (no != NULL) {
        apagaNo(no->Esq);
        apagaNo(no->Dir);
        free(no);
    }
}

void apagaFP(TipoFP *fp) {
    apagaNo(*fp);
    *fp = NULL;
}

void imprimeNo(TipoApontador no) {
    if (no != NULL) {
        imprimeNo(no->Dir);
        printf("%ld ", no->reg.chave);
        imprimeNo(no->Esq);
    }
}

void imprimeFP(TipoFP fp) {
    imprimeNo(fp);
    printf("\n");
}

void insereFP(TipoRegistro x, TipoFP *fp) {
    if (*fp == NULL) {
        *fp = (TipoFP) malloc(sizeof(TipoNo));
        (*fp)->reg = x;
        (*fp)->Esq = NULL;
        (*fp)->Dir = NULL;
        criaFilaFIFO(&(*fp)->filaFIFO);
        enfileiraFilaFIFO(&(*fp)->filaFIFO, x);
    }

    if (x.chave < (*fp)->reg.chave) {
        insereFP(x, &(*fp)->Esq); // Insere na subárvore esquerda
    } else if (x.chave > (*fp)->reg.chave) {
        insereFP(x, &(*fp)->Dir); // Insere na subárvore direita
    } else {
        enfileiraFilaFIFO(&(*fp)->filaFIFO, x); // Chave já existe, enfileira na fila FIFO
    }
}

void retiramax(TipoRegistro *x, TipoFP *fp) {
    if (*fp == NULL) return;

    if ((*fp)->Dir != NULL) {
        retiramax(x, &(*fp)->Dir);
    } else {
        *x = (*fp)->filaFIFO.primeiro->registro;  // Copia o primeiro registro da fila FIFO para x

        TipoFP aux = *fp;
        *fp = (*fp)->Esq;  // Promove a subárvore esquerda, se existir

        // Liberar a memória do nó encontrado
        while (!vaziaFilaFIFO(&aux->filaFIFO)) {  // Remove todos os elementos da fila FIFO
            desenfileiraFilaFIFO(&aux->filaFIFO, x);
        }
        free(aux);  // Libera o nó
    }
}
