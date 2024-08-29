#include <stdio.h>
#include "arvore.h"

int main() {
    TipoFP fp;
    int maxValue;

    // Cria uma fila de prioridades vazia (árvore binária de busca)
    criaFP(&fp);

    // Insere valores na árvore
    insereFP(50, &fp);
    insereFP(30, &fp);
    insereFP(70, &fp);
    insereFP(20, &fp);
    insereFP(40, &fp);
    insereFP(60, &fp);
    insereFP(80, &fp);

    // Imprime a árvore em ordem decrescente
    printf("Fila de prioridades em ordem decrescente:\n");
    imprimeFP(fp);
    printf("\n");

    // Remove o maior valor
    retiramax(&maxValue, &fp);
    printf("Maior valor removido: %d\n", maxValue);

    // Imprime a árvore novamente após remover o maior valor
    printf("Fila de prioridades apos remover o maior valor:\n");
    imprimeFP(fp);
    printf("\n");

    int removeValue = 30;
    printf("Removendo o valor: %d\n", removeValue);
    retiraNo(removeValue, &fp);

    // Imprime a árvore novamente após remover o valor específico
    printf("Fila de prioridades apos remover o valor %d:\n", removeValue);
    imprimeFP(fp);
    printf("\n");

    int searchValue = 40;
    TipoFP foundNode = searchItem(searchValue, &fp);
    if (foundNode) {
        printf("Item %d encontrado na arvore.\n", searchValue);
    } else {
        printf("Item %d nao encontrado na arvore.\n", searchValue);
    }

    // Apaga a árvore e libera a memória
    apagaFP(&fp);

    return 0;
}
