#include "busca.h"
#include <stdio.h>

int buscaBinaria(int vetor[], int *comparacoes, int elemento, int tamanho) {
    int direita = 0;
    int esquerda = tamanho - 1;

    while (esquerda >= direita) {
        (*comparacoes)++;
        int comp = esquerda + (direita - esquerda) / 2;

        if (elemento == vetor[comp]) {
            return elemento;
        } else if (elemento > vetor[comp]) {
            direita = comp + 1;
        } else {
            esquerda = comp - 1;
        }
    }


    return 1;
}
