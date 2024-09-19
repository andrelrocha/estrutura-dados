#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j]; // Desloca o valor maior para a direita
            j = j - 1;       // Avança para o próximo elemento à esquerda
        }

        arr[j + 1] = chave;
    }
}

int particionar(int arr[], int alto, int baixo) {
    int pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }

    int aux = arr[i+1];
    arr[i+1] = arr[alto];
    arr[alto] = aux;

    return i+1;
}

void quicksort(int arr[], int alto, int baixo) {
    if (baixo < alto) {
        int pivoindex = particionar(arr, alto, baixo);
        quicksort(arr, pivoindex-1, baixo);
        quicksort(arr, alto, pivoindex+1);
    }
}

int merge(int arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

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

void mergesort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergesort(arr, inicio, meio);
        mergesort(arr, meio+1, fim);

        merge(arr, inicio, meio, fim);
    }
}

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

void shellSort(int A[], int n) {
    // Inicializa o gap (distância entre os elementos a serem comparados)
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realiza a ordenação por inserção para o intervalo atual
        for (int i = gap; i < n; i++) {
            int temp = A[i];
            int j = i;

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
