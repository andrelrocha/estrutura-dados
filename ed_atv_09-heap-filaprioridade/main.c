#include <stdio.h>
#include <stdlib.h>
#include "FP.h"
#include "Heapsort.h"

int main() {
    FP filaPrioridade;
    TipoRegistro registro, removido;

    // Inicializa a fila de prioridade
    criaFP(&filaPrioridade);

    // Insere 3 registros na fila de prioridade com chave 20
    registro.chave = 20;
    insereFP(&filaPrioridade, registro);
    insereFP(&filaPrioridade, registro);
    insereFP(&filaPrioridade, registro);

    // Insere outros registros com chaves diferentes
    registro.chave = 10;
    insereFP(&filaPrioridade, registro);

    registro.chave = 30;
    insereFP(&filaPrioridade, registro);

    // Imprime o estado inicial da fila de prioridade
    printf("Fila de Prioridade Inicial:\n");
    imprimeFP(&filaPrioridade);

    // Remove o registro de maior prioridade (30)
    if (removeFP(&filaPrioridade, &removido)) {
        printf("Registro removido: %ld\n", removido.chave);
    }

    // Imprime o estado da fila de prioridade apos a remocao do maior elemento
    printf("Fila de Prioridade apos remocao:\n");
    imprimeFP(&filaPrioridade);

    // Remove novamente (deve remover um dos elementos da fila com chave 20)
    if (removeFP(&filaPrioridade, &removido)) {
        printf("Registro removido: %ld\n", removido.chave);
    }

    // Imprime o estado final da fila de prioridade
    printf("Fila de Prioridade Final:\n");
    imprimeFP(&filaPrioridade);

    printf("Chamando heapsort...\n");
    heapsortMain();

    return 0;
}
