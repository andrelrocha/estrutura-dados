#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void imprime_lista(TipoLista* lista) {
    Celula* atual = lista->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}


int main()
{
    TipoLista lista;

    fazListaVazia(&lista);
    printf("Lista inicializada.\n");
    imprime_lista(&lista);

    printf("Inserindo elementos na lista...\n");
    insereLista(&lista, 10);
    insereLista(&lista, 20);
    insereLista(&lista, 30);
    imprime_lista(&lista);

    printf("Tamanho da lista: %d\n", lista.tamanho);

    printf("Removendo elemento com chave 20...\n");
    buscaRemoveDaLista(&lista, 20);
    imprime_lista(&lista);

    printf("Tamanho da lista: %d\n", lista.tamanho);

    printf("Removendo elemento com chave 10...\n");
    buscaRemoveDaLista(&lista, 10);
    imprime_lista(&lista);

    printf("Tamanho da lista: %d\n", lista.tamanho);

    printf("Removendo elemento com chave 30...\n");
    buscaRemoveDaLista(&lista, 30);
    imprime_lista(&lista);

    printf("Tamanho da lista: %d\n", lista.tamanho);
}
