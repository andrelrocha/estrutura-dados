#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main()
{
    ConjuntoDeInteiros conjunto;
    int elemento;
    int *maiorElemento;
    int *menorElemento;

    fazConjuntoVazio(conjunto);

    insereNoConjunto(5, conjunto);
    insereNoConjunto(10, conjunto);
    insereNoConjunto(20, conjunto);
    printf("Imprimindo o conjunto apos inserir elementos: \n");
    imprimeConjunto(conjunto);

    printf("Pertence ao conjunto (10): %d\n", pertenceAoConjunto(10, conjunto));
    retiraDoConjunto(10, conjunto);
    printf("Pertence 10 (depois de retirar): %d\n", pertenceAoConjunto(10, conjunto));

    if (maxDoConjunto(&elemento, conjunto)) {
        printf("Max do conjunto: %d\n", elemento);
    } else {
        printf("Conjunto vazio\n");
    }

    return 0;
}
