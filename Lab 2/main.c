// Written by Eduardo Wallén and Junior Corazza 2020-03-05
#include "header.h"

int main() {

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

	/* TEST FUNCTIONS FOR SORTING PROBLEMS */
	// arrays to use when testing the files, replace the paths with your local path for the sorting problem you want to run. Yes, we could have made this prettier...
	char sortingProblem1[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-1-problem" };
	char sortingSolution1[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-1-solution" };
	int* problemArr1 = load_file(sortingProblem1);
	int* problemArr2 = load_file(sortingProblem1);
	int* problemArr3 = load_file(sortingProblem1);
	int* solutionArr1 = load_file(sortingSolution1);
	int* solutionArr2 = load_file(sortingSolution1);
	int* solutionArr3 = load_file(sortingSolution1);
	char sortingProblem2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-1-problem" };
	char sortingSolution2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-1-solution" };
	int* problemArr4 = load_file(sortingProblem2);
	int* problemArr5 = load_file(sortingProblem2);
	int* problemArr6 = load_file(sortingProblem2);
	int* solutionArr4 = load_file(sortingSolution2);
	int* solutionArr5 = load_file(sortingSolution2);
	int* solutionArr6 = load_file(sortingSolution2);
	testProblem(problemArr1, solutionArr1, "merge", "");
	testProblem(problemArr2, solutionArr2, "insert", "asc");
	testProblem(problemArr3, solutionArr3, "insert", "desc");
	testProblem(problemArr4, solutionArr4, "merge", "");
	testProblem(problemArr5, solutionArr5, "insert", "asc");
	testProblem(problemArr6, solutionArr6, "insert", "desc");
	
}