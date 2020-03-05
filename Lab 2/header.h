#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 6
#define PNR_LEN 10

void print(int arr[], int length); 
void insertionSort(int arr[], int length, int smallest);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int p, int r);
void testInsertionSortAscending_L1();
void testInsertionSortDescending_L1();
void testInsertionSortAscending_L2();
void testInsertionSortDescending_L2();
void testInsertionSortAscending_pnum();
void testInsertionSortDescending_pnum();
void testMergeSort_L1();
void testMergeSort_L2();
void testMergeSort_pnum();
void resetLists();
