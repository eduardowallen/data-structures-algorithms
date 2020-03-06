// Written by Eduardo Wallén and Junior Corazza 2020-03-05
#include "header.h"

int main() {
	char sortingProblem[] = { "sorting_problems/test-10-1-problem" };
	int* problemArr = load_file(sortingProblem);
	print(problemArr, problemArr[0]);

	testInsertionSortAscending_L1();
	testInsertionSortDescending_L1();
	testInsertionSortAscending_L2();
	testInsertionSortDescending_L2();
	testInsertionSortAscending_pnum();
	testInsertionSortDescending_pnum();
	resetLists();
	testMergeSort_L1();
	testMergeSort_L2();
	testMergeSort_pnum();
	testProblem(problemArr, "insert", "asc");
}