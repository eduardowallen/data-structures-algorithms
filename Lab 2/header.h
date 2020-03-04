#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 6
#define PNR_LEN 10

void print(int arr[], int length); 
void insertionSort(int arr[], int length, int smallest);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int p, int r);