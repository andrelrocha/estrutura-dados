#include <stdio.h>
#include <stdlib.h>

int main()
{
    //selection sort
    int array[] = {64, 25, 12, 22, 11};
    int n = 5;

    printf("Array original: \n");
    imprime_array(array, n);

    selectionSort(array, n);

    printf("Array ordenado por selection sort: \n");
    imprime_array(array, n);


    //insert sort
    int array2[] = {12, 11, 13, 5, 6};
    printf("Array original: \n");
    imprime_array(array2, n);

    insertionSort(array2, n);

    printf("Array ordenado por insertion sort: \n");
    imprime_array(array2, n);

    //shell sort
    int array3[] = {12, 34, 54, 2, 3};

    printf("Array original: \n");
    imprime_array(array3, n);

    shellSort(array3, n);

    printf("Array ordenado por shell sort: \n");
    imprime_array(array3, n);

    return 0;
}
