#include <stdio.h>

void heapSort(int arr[], int n) {
    // Extraindo elementos do heap um por um
    for (int i = n - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapificar a subárvore afetada
        int j = 0;
        while (1) {
            int maior = j;
            int esquerda = 2 * j + 1;
            int direita = 2 * j + 2;

            // Se o filho esquerdo for maior que o nó atual
            if (esquerda < i && arr[esquerda] > arr[maior]) {
                maior = esquerda;
            }

            // Se o filho direito for maior que o maior até agora
            if (direita < i && arr[direita] > arr[maior]) {
                maior = direita;
            }

            // Se o maior não for o nó atual
            if (maior != j) {
                int temp = arr[j];
                arr[j] = arr[maior];
                arr[maior] = temp;
                j = maior;
            } else {
                break;
            }
        }
    }
}

///////////////////////////////////////////////////

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            // Código de troca inline
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;

    return i + 1;
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivoIndex = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pivoIndex - 1);
        quickSort(arr, pivoIndex + 1, alto);
    }
}

/////////////////////////////////////////////////////////////////////

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // Tamanho do subarray esquerdo
    int n2 = r - m;     // Tamanho do subarray direito

    // Arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Intercala os arrays temporários de volta em arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Encontra o ponto médio

        // Ordena a primeira e a segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Intercala as duas metades
        merge(arr, l, m, r);
    }
}

///////////////////////

void imprimeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
