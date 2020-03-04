#include "header.h"

#define ARR_LEN 6
#define PNR_LEN 10
#define NUM(a) (sizeof(a) / sizeof(*a))

int main() {
	int L1[ARR_LEN] = { 3, 1, 5, 10, 8, 7 };
	int L2[ARR_LEN] = { 5, 2, 9, 6, 1, 2 };
	int pnum[PNR_LEN] = { 9, 0, 1, 1, 2, 6, 0, 9, 3, 3 };
	
	// TEST CASES

		// CASE ONE
			// NORMAL SORT (List 1)
			insertionSort(L1, NUM(L1), 1);
			// BACKWARD SORT (List 1)
			insertionSort(L1, NUM(L1), 0);

		// CASE TWO
			// NORMAL SORT (List 2)
			insertionSort(L2, NUM(L2), 1);
			// BACKWARD SORT (List 2)
			insertionSort(L2, NUM(L2), 0);

		// CASE THREE
			// NORMAL SORT (Personal number)
			insertionSort(pnum, NUM(pnum), 1);
			// BACKWARD SORT (Personal number)
			insertionSort(pnum, NUM(pnum), 0);
			
		// Exercise 2

			print(L1, NUM(L1));
			mergeSort(L1, 0, ARR_LEN-1);
			print(L1, NUM(L1));
			print(L2, NUM(L2));
			mergeSort(L2, 0, ARR_LEN-1);
			print(L2, NUM(L2));
			print(pnum, NUM(pnum));
			mergeSort(pnum, 0, PNR_LEN-1);
			print(pnum, NUM(pnum));
}