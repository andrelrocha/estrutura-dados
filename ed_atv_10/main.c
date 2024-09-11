#include <stdio.h>
#include <stdlib.h>
#include "file.h"

long long int compSelecao = 0, movSelecao = 0;
long long int compInsercao = 0, movInsercao = 0;
long long int compShellsort = 0, movShellsort = 0;

int main()
{
    int tamanhos[] = {500, 5000, 10000, 30000};
    long long int compSelecaoCounts[4], movSelecaoCounts[4];
    long long int compInsercaoCounts[4], movInsercaoCounts[4];
    long long int compShellsortCounts[4], movShellsortCounts[4];

    srand(time(NULL));

    for (int s = 0; s < 4; s++) {
        int n = tamanhos[s];
        TipoItem *arrayOriginal = (TipoItem *)malloc(n * sizeof(TipoItem));
        TipoItem *arraySelecao = (TipoItem *)malloc(n * sizeof(TipoItem));
        TipoItem *arrayInsercao = (TipoItem *)malloc(n * sizeof(TipoItem));
        TipoItem *arrayShellsort = (TipoItem *)malloc(n * sizeof(TipoItem));

        // Preenche o arrayOriginal com valores aleatórios
        for (int i = 0; i < n; i++) {
            arrayOriginal[i].Chave = rand();
        }

        // Copia o arrayOriginal para os outros arrays
        memcpy(arraySelecao, arrayOriginal, n * sizeof(TipoItem));
        memcpy(arrayInsercao, arrayOriginal, n * sizeof(TipoItem));
        memcpy(arrayShellsort, arrayOriginal, n * sizeof(TipoItem));

        // Reseta os contadores
        compSelecao = movSelecao = 0;
        compInsercao = movInsercao = 0;
        compShellsort = movShellsort = 0;

        // Ordena com Seleção
        Selecao(arraySelecao, n);
        compSelecaoCounts[s] = compSelecao;
        movSelecaoCounts[s] = movSelecao;

        // Ordena com Inserção
        Insercao(arrayInsercao, n);
        compInsercaoCounts[s] = compInsercao;
        movInsercaoCounts[s] = movInsercao;

        // Ordena com Shellsort
        Shellsort(arrayShellsort, n);
        compShellsortCounts[s] = compShellsort;
        movShellsortCounts[s] = movShellsort;

        // Libera os arrays
        free(arrayOriginal);
        free(arraySelecao);
        free(arrayInsercao);
        free(arrayShellsort);
    }

    // Imprime a tabela de comparações
    printf("Numero de comparacoes de chaves dos metodos de ordenacao\n");
    printf("(Array inicial com registros em ordem aleatoria)\n");
    printf("+--------------------------------------------------------------+\n");
    printf("| Metodo        |   500   |  5000   | 10000  | 30000  |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("| Selecao       |");
    for (int s = 0; s < 4; s++) {
        printf(" %7lld |", compSelecaoCounts[s]);
    }
    printf("\n");
    printf("| Insercao      |");
    for (int s = 0; s < 4; s++) {
        printf(" %7lld |", compInsercaoCounts[s]);
    }
    printf("\n");
    printf("| Shellsort     |");
    for (int s = 0; s < 4; s++) {
        printf(" %7lld |", compShellsortCounts[s]);
    }
    printf("\n");
    printf("+--------------------------------------------------------------+\n");

    // Imprime a tabela de movimentações
    printf("\nNumero de movimentacoes de chaves dos metodos de ordenacao\n");
    printf("(Array inicial com registros em ordem aleatoria)\n");
    printf("+--------------------------------------------------------------+\n");
    printf("| Metodo        |   500   |  5000   | 10000  | 30000  |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("| Selecao       |");
    for (int s = 0; s < 4; s++) {
        printf(" %7lld |", movSelecaoCounts[s]);
    }
    printf("\n");
    printf("| Insercao      |");
    for (int s = 0; s < 4; s++) {
        printf(" %7lld |", movInsercaoCounts[s]);
    }
    printf("\n");
    printf("| Shellsort     |");
    for (int s = 0; s < 4; s++) {
        printf(" %7lld |", movShellsortCounts[s]);
    }
    printf("\n");
    printf("+--------------------------------------------------------------+\n");

    return 0;
}
