#include <stdio.h>
#include <stdlib.h>
#include "TipoFP.h"

int main() {
    TipoFP filaPrioridade;
    TipoRegistro registro;

    // Cria a fila de prioridades
    criaFP(&filaPrioridade);

    // Verifica se a fila de prioridades está vazia
    if (filaPrioridade == NULL) {
        printf("A fila de prioridades esta vazia.\n");
    }

    // Adiciona alguns registros na fila de prioridades
    for (int i = 1; i <= 5; i++) {
        registro.chave = i;
        insereFP(registro, &filaPrioridade);
        if (i == 2) {
            insereFP(registro, &filaPrioridade);
        }
    }

    // Imprime a fila de prioridades em ordem decrescente
    printf("Conteudo da fila de prioridades em ordem decrescente:\n");
    imprimeFP(filaPrioridade);

    // Remove o elemento com a maior chave da fila de prioridades
    TipoRegistro maxRegistro;
    retiramax(&maxRegistro, &filaPrioridade);
    printf("Maior elemento desenfileirado.\n");

    // Imprime a fila de prioridades após remover o maior elemento
    printf("Conteudo da fila de prioridades apos remover o maior elemento:\n");
    imprimeFP(filaPrioridade);

    // Apaga a fila de prioridades e libera a memória
    apagaFP(&filaPrioridade);

    // Verifica se a fila de prioridades está vazia novamente
    if (filaPrioridade == NULL) {
        printf("A fila de prioridades esta vazia apos apagar.\n");
    }

    return 0;
}
