#include "header.h"

/* Function to sort an array using insertion sort*/
void print(int arr[], int length) {
    int i;
    for (i = 1; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int length, int smallest)
{
    int i, key, j;
    /*
    int L1[6] = { 3, 1, 5, 10, 8, 7 };
    int L2[6] = { 5, 2, 9, 6, 1, 2 };
    int pnum[10] = { 9, 0, 1, 1, 2, 6, 0, 9, 3, 3 };
    */
    for (i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;
        //printf("key = %d \n", key);
        //printf("j = %d \n", arr[j]);
        //printf("i = %d \n", arr[i]);
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        if (smallest) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else {
            while (j > 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
    print(arr, length);
}

