#include "header.h"

#define ARR_LEN 6
#define PNR_LEN 10
#define NUM(a) (sizeof(a) / sizeof(*a))

int main() {
	int L1[ARR_LEN] = { 3, 1, 5, 10, 8, 7 };
	int L2[ARR_LEN] = { 5, 2, 9, 6, 1, 2 };
	int pnum[PNR_LEN] = { 9, 0, 1, 1, 2, 6, 0, 9, 3, 3 };
	int length;

	// TEST CASES (First integer ([0]) is currently being skipped... Find a fix for it before continuing.

		// CASE ONE
			// NORMAL SORT (List 1)
			length = NUM(L1);
			insertionSort(L1, length, 1);
			// BACKWARD SORT (List 1)
			insertionSort(L1, length, 0);

		// CASE TWO
			// NORMAL SORT (List 2)
			length = NUM(L2);
			insertionSort(L2, length, 1);
			// BACKWARD SORT (List 2)
			insertionSort(L2, length, 0);

		// CASE THREE
			// NORMAL SORT (Personal number)
			length = NUM(pnum);
			insertionSort(pnum, length, 1);
			// BACKWARD SORT (Personal number)
			insertionSort(pnum, length, 0);
}