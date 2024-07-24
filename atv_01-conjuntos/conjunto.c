#include "conjunto.h"
#include <stdio.h>

void fazConjuntoVazio(ConjuntoDeInteiros conjunto) {
    for (int i = 0; i < MAX_SIZE; i++) {
        conjunto[i] = 0;
    }
}

void imprimeConjunto(ConjuntoDeInteiros conjunto) {
    printf("{\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d, \n", conjunto[i]);
    }
    printf("/n}");
}

int insereNoConjunto(int elemento, ConjuntoDeInteiros conjunto) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (conjunto[i] == elemento) {
            return 0;
        }
    }
    for (int j = 0; j < MAX_SIZE; j++) {
        if (conjunto[j] == 0) {
            conjunto[j] = elemento;
            return 1;
        }
    }
}

int pertenceAoConjunto(int elemento, ConjuntoDeInteiros conjunto) {
    for (int j = 0; j < MAX_SIZE; j++) {
        if (conjunto[j] == elemento) {
            return 1;
        }
    }
    return 0;
}

int retiraDoConjunto(int elemento, ConjuntoDeInteiros conjunto) {
    for (int j = 0; j < MAX_SIZE; j++) {
        if (conjunto[j] == elemento) {
            conjunto[j] = 0;
            return 1;
        }
    }

    return 0;
}

int maxDoConjunto(int *elemento, ConjuntoDeInteiros conjunto) {
    int max = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (conjunto[i] > max) {
            max = conjunto[i];
        }
    }
    *elemento = max;
    return 1;

    if (max == 0 ) {
        return 0;
    }
}

int maxMinDoConjunto(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto) {
    return 1;
}

/*
int maxMinDoConjunto(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto);
int maxMinDoConjunto2(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto);
*/
