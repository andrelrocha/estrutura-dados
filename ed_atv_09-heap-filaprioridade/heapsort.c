#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Heapsort.h"

#define MAX 10000

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void desce(int *arr, int n, int i, long *comparacoes) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    // Verifica se o filho esquerdo é maior que o pai
    if (esq < n) {
        (*comparacoes)++;
        if (arr[esq] > arr[maior]) {
            maior = esq;
        }
    }

    // Verifica se o filho direito é maior que o maior atual
    if (dir < n) {
        (*comparacoes)++;
        if (arr[dir] > arr[maior]) {
            maior = dir;
        }
    }

    // Se o maior não for o pai, realiza a troca e continua ajustando o heap
    if (maior != i) {
        troca(&arr[i], &arr[maior]);
        desce(arr, n, maior, comparacoes);
    }
}

void heapsort(int *arr, int n, long *comparacoes) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(arr, n, i, comparacoes);
    }

    // Extrai os elementos do heap um a um
    for (int i = n - 1; i > 0; i--) {
        troca(&arr[0], &arr[i]);

        // Chama desce para o heap reduzido
        desce(arr, i, 0, comparacoes);
    }
}

void preencheCrescente(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void preencheDecrescente(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1;
    }
}

void preencheAleatorio(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

int heapsortMain() {
    int arr[MAX];
    long comparacoes;

    srand(time(NULL));

    // Heapsort com array ordenado
    preencheCrescente(arr, MAX);
    comparacoes = 0;
    heapsort(arr, MAX, &comparacoes);
    printf("Heapsort com array de 10000 itens ordenados fez %ld comparacoes de chave\n", comparacoes);

    // Heapsort com array inversamente ordenado
    preencheDecrescente(arr, MAX);
    comparacoes = 0;
    heapsort(arr, MAX, &comparacoes);
    printf("Heapsort com array de 10000 itens ordenados inversamente fez %ld comparacoes de chave\n", comparacoes);

    // Heapsort com array aleatório
    preencheAleatorio(arr, MAX);
    comparacoes = 0;
    heapsort(arr, MAX, &comparacoes);
    printf("Heapsort com array de 10000 itens aleatorios fez %ld comparacoes de chave\n", comparacoes);

    return 0;
}

