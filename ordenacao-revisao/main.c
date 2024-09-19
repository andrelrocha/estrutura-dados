#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[6] = {64, 25, 12, 22, 11, 90};
    int n = 6;

    printf("Array desordenado: \n");
    imprime_array(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado por selection sort: \n");
    imprime_array(arr, n);

    int arr2[6] = {64, 25, 12, 22, 11, 90};

    printf("Array desordenado: \n");
    imprime_array(arr2, n);

    insertionSort(arr2, n);

    printf("Array ordenado por insertion sort: \n");
    imprime_array(arr2, n);

    int arr3[6] = {64, 25, 12, 22, 11, 90};

    printf("Array desordenado: \n");
    imprime_array(arr3, n);

    quicksort(arr3, n-1, 0);

    printf("Array ordenado por quick sort: \n");
    imprime_array(arr3, n);

    // Testando ShellSort
    int arr4[6] = {64, 25, 12, 22, 11, 90};

    printf("Array desordenado para shell sort: \n");
    imprime_array(arr4, n);

    shellSort(arr4, n);

    printf("Array ordenado por shell sort: \n");
    imprime_array(arr4, n);

    // Testando MergeSort
    int arr5[6] = {64, 25, 12, 22, 11, 90};

    printf("Array desordenado para merge sort: \n");
    imprime_array(arr5, n);

    mergesort(arr5, 0, n - 1);

    printf("Array ordenado por merge sort: \n");
    imprime_array(arr5, n);


    int array[] = {50, 30, 20, 15, 10, 90};

    printf("Array original: \n");
    imprime_array(array, n);

    heapSort(array, n);

    printf("Array ordenado por heap sort: \n");
    imprime_array(array, n);

    return 0;
}
