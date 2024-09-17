#include <stdlib.h>
#include <stdio.h>

void selectionSort(int A[], int n) {
    int i, j, min_idx;

    // Percorre o array
    for (i = 0; i < n-1; i++) {
        // Encontra o menor elemento na parte não ordenada
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor elemento com o primeiro elemento não ordenado
        if (min_idx != i) {
            int temp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = temp;
        }
    }
}

void insertionSort(int A[], int n) {
    int i, chave, j;

    // O loop começa no segundo elemento (índice 1), pois o primeiro já é considerado ordenado
    for (i = 1; i < n; i++) {
        // A chave é o elemento atual que será inserido na posição correta
        chave = A[i];

        // j é o índice do elemento anterior ao atual (índice i)
        // Este loop move os elementos maiores que a chave uma posição para a frente
        // para abrir espaço para a chave ser inserida na posição correta
        j = i - 1;

        // Enquanto o elemento anterior for maior que a chave e o índice for válido (j >= 0),
        // movemos o elemento A[j] para A[j+1], empurrando o valor para a direita
        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j]; // Desloca o valor maior para a direita
            j = j - 1;       // Avança para o próximo elemento à esquerda
        }

        // Quando o loop termina, j será o índice do elemento que é menor (ou igual) à chave,
        // então a chave é inserida na posição j + 1
        A[j + 1] = chave;
    }
}

void shellSort(int A[], int n) {
    int gap, i, j, temp;

    // Inicializa o gap (distância entre os elementos a serem comparados)
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Realiza a ordenação por inserção para o intervalo atual
        for (i = gap; i < n; i++) {
            temp = A[i];
            j = i;

            // Move os elementos do intervalo para a posição correta
            while (j >= gap && A[j - gap] > temp) {
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = temp;
        }
    }
}

void imprime_array(int a[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
