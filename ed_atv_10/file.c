#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "file.h"

void Selecao(TipoItem *A, int n) {
    int i, j, min;
    TipoItem temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            compSelecao++;
            if (A[j].Chave < A[min].Chave) {
                min = j;
            }
        }
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            movSelecao += 3; // 3 movimentações
        }
    }
}

void Insercao(TipoItem *A, int n) {
    int i, j;
    TipoItem temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        movInsercao++; // Uma movimentação
        j = i - 1;
        compInsercao++; // Primeira comparação
        while (j >= 0 && temp.Chave < A[j].Chave) {
            A[j + 1] = A[j];
            movInsercao++; // Uma movimentação
            j--;
            if (j >= 0)
                compInsercao++; // Comparações subsequentes
        }
        A[j + 1] = temp;
        movInsercao++; // Uma movimentação
    }
}

void Shellsort(TipoItem *A, int n) {
    int i, j, h;
    TipoItem temp;
    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            temp = A[i];
            movShellsort++; // Uma movimentação
            j = i;
            compShellsort++; // Primeira comparação
            while (j >= h && temp.Chave < A[j - h].Chave) {
                A[j] = A[j - h];
                movShellsort++; // Uma movimentação
                j -= h;
                if (j >= h)
                    compShellsort++; // Comparações subsequentes
            }
            A[j] = temp;
            movShellsort++; // Uma movimentação
        }
    }
}
