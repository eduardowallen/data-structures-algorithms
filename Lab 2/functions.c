#include "header.h"
#pragma warning (disable: 6386 6385 6011)
/* Function to sort an array using insertion sort*/
void print(int arr[], int length) {
	int i;
	for (i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void insertionSort(int arr[], int length, int smallest)
{
	int i, key, j;
	/*
	***These are the arrays we're working with****
	________________________________________________
	int L1[6] = { 3, 1, 5, 10, 8, 7 };
	int L2[6] = { 5, 2, 9, 6, 1, 2 };
	int pnum[10] = { 9, 0, 1, 1, 2, 6, 0, 9, 3, 3 };
	________________________________________________
	*/
	for (i = 1; i < length; i++) { // "i" is the "right" box
		key = arr[i];	// We copy the value of the data inside a[i]
		j = i - 1;		// We set j to be the predecessor of i

		// If "smallest" is set to 1 we want to sort in ascending order
		if (smallest) {
			while (j >= 0 && arr[j] > key) {	// If we're inside the array (j>=0) and predecessor is smaller than the successor (right int is smaller than the left int)
				arr[j + 1] = arr[j];	// Set the right int to be the left int
				j = j - 1;				// update the index of j (see why on row 38)
			}
		} else { // We want to sort in descending order
			while (j >= 0 && arr[j] < key) { // If we're inside the array (j>=0) and predecessor is larger than the successor (right int is larger than the left int)
				arr[j + 1] = arr[j];	// Set the right int to be the left int
				j = j - 1;				// update the index of j (see why on row 38)
			}
		}
		// Now set the left int to be equal to the int(key) we saved in the beginning
		arr[j + 1] = key;
	}
	print(arr, length);	// Prints the array so we can see the result
}

void merge(int arr[], int p, int q, int r) {
	int i, j, k;                // Integers that hold values
	int n1 = q - p + 1;         // Amount of elements in the left array
	int n2 = r - q;             // Amount of elements in the right array
	int* L = NULL, * R = NULL;   // Create pointers to left and right part of the array we split
	L = malloc(n1 * sizeof(*L));    // Allocate memory for the left part of the array based on its size
	R = malloc(n2 * sizeof(*R));    // Allocate memory for the right part of the array based on its size
	if (L == NULL && R == NULL) {   // Check if the memory was allocated in both left (L) and right (R) and exit if it wasn't
		printf("Memory could not be allocated.\n");
		exit(0);
	}
	for (i = 0; i < n1; i++)  // Iterate through the left array
		L[i] = arr[p + i];		// Insert the integers into the left part of the array
	for (j = 0; j < n2; j++)  // Iterate through the right array
		R[j] = arr[q + 1 + j];	//Insert the integers into the right part of the array

	// Now we merge the temporary arrays into arr[]
	i = 0;	// index of left subarray
	j = 0;	// index of right subarray
	k = p;	// index of merged subarray
	for (; i < n1 && j < n2;) {	// iterate through the subarrays
		if (L[i] <= R[j]){			// checks if the (index of) left subarray is lower than or equal to (index of) the right subarray
			arr[k] = L[i];			// inserts the integer from the left subarray into our merged array
			i++;					// increments the index of the left subarray
		} else {				// If the right subarray is lower than the left subarray...
			arr[k] = R[j];			// insert the integer from the right subarray into our merged array
			j++;					// increment the index of the right subarray
		} k++;			// increment the index of our merged array
	}
	// Copy the remaining elements of L[], if there are any
	while (i < n1) {	// check wether we have iterated through the entire scope of the left array
		arr[k] = L[i];	// add the remaining integers from our left subarray (as the integers in the left subarray is lower than those in the right subarray) into our merged array arr[]
		i++; k++;		// increment the index of the left subarray as well as the merged array arr[]
	}
	// Copy the remaining elements of R[], if there are any
	while (j < n2) {	// check wether we have iterated through the entire scope of the right subarray
		arr[k] = R[j];	// add the remaining integers from our right subarray into our merged array arr[]
		j++; k++;		// increment the index of the right subarray as well as the merged array arr[]
	}
	free(L); free(R);	// Free the allocated memory for the temporary array L[] and R[]
}

void mergeSort(int arr[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		// Divide and Conquer (recursive with itself)
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		// Combine with merge
		merge(arr, p, q, r);
	}
}