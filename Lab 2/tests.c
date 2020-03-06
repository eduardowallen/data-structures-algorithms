// Written by Eduardo Wall�n and Junior Corazza 2020-03-05
#include "header.h"
#define ARR_LEN 6
#define PNR_LEN 10
#define NUM(a) (sizeof(a) / sizeof(*a))

/* These are the arrays we're working with */
int L1[ARR_LEN] = { 3, 1, 5, 10, 8, 7 };
int L2[ARR_LEN] = { 5, 2, 9, 6, 1, 2 };
int pnum[PNR_LEN] = { 9, 0, 1, 1, 2, 6, 0, 9, 3, 3 };

// Function to reset all lists to their original state
void resetLists() {
	L1[0] = 3; L1[1] = 1; L1[2] = 5; L1[3] = 10; L1[4] = 8; L1[5] = 7;
	L2[0] = 5; L2[1] = 2; L2[2] = 9; L2[3] = 6; L2[4] = 1; L2[5] = 2;
	pnum[0] = 9; pnum[1] = 0; pnum[2] = 1; pnum[3] = 1; pnum[4] = 2; pnum[5] = 6; pnum[6] = 0; pnum[7] = 9; pnum[8] = 3; pnum[9] = 3;
}
/********************************
***** TESTS FOR EXERCISE 4 ******
*********************************/

// Tests for insertionSort
void testInsertionSortAscending_L1() {
	printf("testInsertionSortAscending_L1\n");
	print(L1, NUM(L1));
	// Sort ascending (List 1)
	insertionSort(L1, NUM(L1), 1);
	printf("End of test\n\n");
}
void testInsertionSortDescending_L1() {
	printf("testInsertionSortDescending_L1\n");
	print(L1, NUM(L1));
	// Sort descending (List 1)
	insertionSort(L1, NUM(L1), 0);
	printf("End of test\n\n");
}
void testInsertionSortAscending_L2() {
	printf("testInsertionSortAscending_L2\n");
	print(L2, NUM(L2));
	// Sort ascending (List 2)
	insertionSort(L2, NUM(L2), 1);
	printf("End of test\n\n");
}
void testInsertionSortDescending_L2() {
	printf("testInsertionSortDescending_L2\n");
	print(L2, NUM(L2));
	// Sort descending (List 2)
	insertionSort(L2, NUM(L2), 0);
	printf("End of test\n\n");
}
void testInsertionSortAscending_pnum() {
	printf("testInsertionSortAscending_pnum\n");
	print(pnum, NUM(pnum));
	// Sort ascending (Personal number)
	insertionSort(pnum, NUM(pnum), 1);
	printf("End of test\n\n");
}
void testInsertionSortDescending_pnum() {
	printf("testInsertionSortDescending_pnum\n");
	print(pnum, NUM(pnum));
	// Sort descending (Personal number)
	insertionSort(pnum, NUM(pnum), 0);
	printf("End of test\n\n");
}

// Tests for mergeSort
void testMergeSort_L1() {
	printf("testMergeSort_L1\n");
	print(L1, NUM(L1));
	mergeSort(L1, 0, ARR_LEN - 1);
	print(L1, NUM(L1));
	printf("End of test\n\n");
}
void testMergeSort_L2() {
	printf("testMergeSort_L2\n");
	print(L2, NUM(L2));
	mergeSort(L2, 0, ARR_LEN - 1);
	print(L2, NUM(L2));
	printf("End of test\n\n");
}
void testMergeSort_pnum() {
	printf("testMergeSort_pnum\n");
	print(pnum, NUM(pnum));
	mergeSort(pnum, 0, PNR_LEN - 1);
	print(pnum, NUM(pnum));
	printf("End of test\n\n");
}
/* Testing our algorithms on the sorting problems */
/* As the program inserts an int at the first entry in the array and you haven't included any README-file whatsoever about how to use or how we should consider the
extra integer that gets added into the array, we now have to include that extra integer and add one more as we didn't account for the function to behave this way and
rearranging the entire array just to get rid of the first int (arr[0]) seems like an awful lot of unnecessary work, so we didn't do that. */

void testProblem(int arr[], int solution[], char type[], char order[]) {
	int start = arr[0];
	if (strcmp(type, "insert") == 0) {
		printf("Insertionsort on problem in %s order:\n", order);
		if (strcmp(order, "asc") == 0) { // Sort incoming array ascending
			insertionSort(arr, start + 1, 1);	// Using insertionSort on the incoming array
			printf("Solution:\n");
			print(solution, solution[0] + 1);
		} 
		else // Sort incoming array descending
			insertionSort(arr, start+1, 0);		// Using insertionSort on the incoming array
	}
	if (strcmp(type, "merge") == 0) {
		printf("Mergesort on problem\n");
		mergeSort(arr, 0, start); // Using mergeSort algorithm on the incoming array
		print(arr, start + 1); 
		printf("Solution:\n");
		print(solution, solution[0] + 1);
	}
	printf("End of test\n\n");
}