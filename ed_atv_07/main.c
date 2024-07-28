#include <stdio.h>
#include "pilha.h"

int main() {
    TipoPilha pilha;
    tipoElemento e;
    int opcao;

    faz_pilha_vazia(&pilha);

    do {
        printf("Menu:\n");
        printf("0 - Sair\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir Pilha\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                printf("Elemento a empilhar: ");
                scanf("%d", &e);
                if (empilha(&pilha, e)) {
                    printf("Elemento %d empilhado.\n", e);
                } else {
                    printf("Erro ao empilhar elemento.\n");
                }
                break;
            case 2:
                if (desempilha(&pilha, &e)) {
                    printf("Elemento %d desempilhado.\n", e);
                } else {
                    printf("Pilha vazia.\n");
                }
                break;
            case 3:
                imprime_pilha(&pilha);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
