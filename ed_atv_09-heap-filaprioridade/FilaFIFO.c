#include <stdlib.h>
#include <stdio.h>
#include "FilaFIFO.h"

void criaFilaFIFO(TipoFilaFIFO *f) {
    f->primeiro = NULL;
    f->ultimo = NULL;
}

int vaziaFilaFIFO(TipoFilaFIFO *f) {
    if (f->primeiro == NULL) return 1;
    return 0;
}

void imprimeFilaFIFO(TipoFilaFIFO *f) {
    if (f->primeiro == NULL) printf("Fila vazia\n");

    RegistroFila *aux = f->primeiro;

    while (aux != NULL) {
        printf("%i ", aux->registro.chave);
        aux = aux->prox;
    }
    printf("\n");
}

void apagaFilaFIFO(TipoFilaFIFO *f) {
    RegistroFila *aux = f->primeiro;
    RegistroFila *apoio = aux;

    while (apoio != NULL) {
        apoio = aux->prox;
        free(aux);
        aux = apoio;
    }

    f->primeiro = NULL;
    f->ultimo = NULL;
}

void enfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro item) {
    RegistroFila* node = malloc(sizeof(RegistroFila));
    node->registro = item;
    node->prox = NULL;

    if (f->primeiro == NULL) {
        f->primeiro = node;
        f->ultimo = node;
    } else {
        RegistroFila *aux = f->primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = node;
        f->ultimo = node;
    }
}

void desenfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro *item) {
    if (f->primeiro == NULL) return 0;

    RegistroFila* primeiro = f->primeiro;
    f->primeiro = primeiro->prox;
    free(primeiro);
    return 1;
}
