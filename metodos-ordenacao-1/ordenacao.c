#include <stdlib.h>
#include <stdio.h>

void selectionSort(int A[], int n) {
    int i, j, min_idx;

    // Percorre o array
    for (i = 0; i < n-1; i++) {
        // Encontra o menor elemento na parte n�o ordenada
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor elemento com o primeiro elemento n�o ordenado
        if (min_idx != i) {
            int temp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = temp;
        }
    }
}

void insertionSort(int A[], int n) {
    int i, chave, j;

    // O loop come�a no segundo elemento (�ndice 1), pois o primeiro j� � considerado ordenado
    for (i = 1; i < n; i++) {
        // A chave � o elemento atual que ser� inserido na posi��o correta
        chave = A[i];

        // j � o �ndice do elemento anterior ao atual (�ndice i)
        // Este loop move os elementos maiores que a chave uma posi��o para a frente
        // para abrir espa�o para a chave ser inserida na posi��o correta
        j = i - 1;

        // Enquanto o elemento anterior for maior que a chave e o �ndice for v�lido (j >= 0),
        // movemos o elemento A[j] para A[j+1], empurrando o valor para a direita
        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j]; // Desloca o valor maior para a direita
            j = j - 1;       // Avan�a para o pr�ximo elemento � esquerda
        }

        // Quando o loop termina, j ser� o �ndice do elemento que � menor (ou igual) � chave,
        // ent�o a chave � inserida na posi��o j + 1
        A[j + 1] = chave;
    }
}

void shellSort(int A[], int n) {
    int gap, i, j, temp;

    // Inicializa o gap (dist�ncia entre os elementos a serem comparados)
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Realiza a ordena��o por inser��o para o intervalo atual
        for (i = gap; i < n; i++) {
            temp = A[i];
            j = i;

            // Move os elementos do intervalo para a posi��o correta
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
