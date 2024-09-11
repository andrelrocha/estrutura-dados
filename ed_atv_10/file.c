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
            movSelecao += 3; // 3 movimenta��es
        }
    }
}

void Insercao(TipoItem *A, int n) {
    int i, j;
    TipoItem temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        movInsercao++; // Uma movimenta��o
        j = i - 1;
        compInsercao++; // Primeira compara��o
        while (j >= 0 && temp.Chave < A[j].Chave) {
            A[j + 1] = A[j];
            movInsercao++; // Uma movimenta��o
            j--;
            if (j >= 0)
                compInsercao++; // Compara��es subsequentes
        }
        A[j + 1] = temp;
        movInsercao++; // Uma movimenta��o
    }
}

void Shellsort(TipoItem *A, int n) {
    int i, j, h;
    TipoItem temp;
    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            temp = A[i];
            movShellsort++; // Uma movimenta��o
            j = i;
            compShellsort++; // Primeira compara��o
            while (j >= h && temp.Chave < A[j - h].Chave) {
                A[j] = A[j - h];
                movShellsort++; // Uma movimenta��o
                j -= h;
                if (j >= h)
                    compShellsort++; // Compara��es subsequentes
            }
            A[j] = temp;
            movShellsort++; // Uma movimenta��o
        }
    }
}
