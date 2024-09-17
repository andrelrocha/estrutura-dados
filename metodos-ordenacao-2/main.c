#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = {50, 30, 20, 15, 10};
    int n = 5;

    printf("Array original: \n");
    imprimeArray(array, 5);

    heapSort(array, n);

    printf("Array ordenado por heap sort: \n");
    imprimeArray(array, n);

    int array2[] = {80, 0, 100, 15, 10};
    printf("Array original: \n");
    imprimeArray(array2, n);

    quickSort(array2, 0, n - 1);

    printf("Array ordenado por quicksort: \n");
    imprimeArray(array2, n);

    int array3[] = {10, 5, 20, 15, 12};
    printf("Array original: \n");
    imprimeArray(array3, n);

    mergeSort(array3, 0, n - 1);

    printf("Array ordenado por mergesort: \n");
    imprimeArray(array3, n);

    return 0;
}
