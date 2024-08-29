#include <stdio.h>
#include "arvore.h"

int main() {
    TipoFP fp;
    int maxValue;

    // Cria uma fila de prioridades vazia (�rvore bin�ria de busca)
    criaFP(&fp);

    // Insere valores na �rvore
    insereFP(50, &fp);
    insereFP(30, &fp);
    insereFP(70, &fp);
    insereFP(20, &fp);
    insereFP(40, &fp);
    insereFP(60, &fp);
    insereFP(80, &fp);

    // Imprime a �rvore em ordem decrescente
    printf("Fila de prioridades em ordem decrescente:\n");
    imprimeFP(fp);
    printf("\n");

    // Remove o maior valor
    retiramax(&maxValue, &fp);
    printf("Maior valor removido: %d\n", maxValue);

    // Imprime a �rvore novamente ap�s remover o maior valor
    printf("Fila de prioridades apos remover o maior valor:\n");
    imprimeFP(fp);
    printf("\n");

    // Apaga a �rvore e libera a mem�ria
    apagaFP(&fp);

    return 0;
}
