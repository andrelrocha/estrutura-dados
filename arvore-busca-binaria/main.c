#include <stdio.h>
#include "arvore.h"

int main()
{
    tipoNo raiz;

    faz_arvore_vazia(&raiz);

    printf("Inserindo elementos na arvore:\n");
    insere_no(&raiz, 50);
    insere_no(&raiz, 30);
    insere_no(&raiz, 70);
    insere_no(&raiz, 20);
    insere_no(&raiz, 40);
    insere_no(&raiz, 60);
    insere_no(&raiz, 80);

    printf("Arvore em ordem:\n");
    imprime_arvore(raiz);
    printf("\n");

    return 0;
}
