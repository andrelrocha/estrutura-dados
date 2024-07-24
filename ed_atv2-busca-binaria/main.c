#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho = 10000;
    int vetor[tamanho];
    for (int j = 0; j < tamanho; j++) {
        vetor[j] = j;
    }

    int comparacoes = 0;

    buscaBinaria(vetor, &comparacoes, 23, tamanho);
    printf("comparacoes: %d", comparacoes);
    return 0;
}
