#include <stdlib.h>
#include "fila.h"

void fazfilavazia(TipoFila* fila) {
    fila->tamanho=0;
    fila->frente=0;
    fila->tras=0;

    for (int i = 0; i < TAM; i++) {
        fila->elementos[i] = 0;
    }
}

int enfileira(TipoFila* fila, int elemento) {
    fila->elementos[fila->tras] = elemento;
    fila->tras = (fila->tras + 1) % TAM;
    fila->tamanho++;
    return 1;
}

int desinfileira(TipoFila* fila) {
    if (fila->tamanho ==0) {
        return 0;
    }
    fila->elementos[fila->frente] = 0;
    fila->frente = (fila->frente+1) % TAM;
    fila->tamanho--;
    return 1;
}

void imprimeFila(TipoFila* fila) {
    printf("Fila: ");
    for (int i = 0; i < TAM; i++) {
        if (fila->tamanho == 0) {
            printf("Vazia.");
            break;
        }
        if (fila->elementos[i] !=0) {
            printf("%d ", fila->elementos[i]);
        }
    }
    printf("\n");
}


int empilha(TipoPilha* pilha, int elemento) {
    pilha->elementos[tras] = elemento;
    pilha->tras++;
    pilha->tamanho++;
    return 1;
}

int desimpilha(TipoPilha* pilha) {
    pilha->elementos[tras] = 0;
    pilha->tras--;
    pilha->tamanho--;
    return 1;
}
