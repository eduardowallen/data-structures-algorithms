// Written by Eduardo Wallén and Junior Corazza 2020-03-05
#include "header.h"

int main() {

	// arrays to use when testing the files, replace the paths with your local path for the sorting problem you want to run
	char sortingProblem1[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-1-problem" };
	char sortingSolution1[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-1-solution" };
	int* problemArr1 = load_file(sortingProblem1);
	int* solutionArr1 = load_file(sortingSolution1);
	char sortingProblem2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-1-problem" };
	char sortingSolution2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-1-solution" };
	int* problemArr2 = load_file(sortingProblem2);
	int* solutionArr2 = load_file(sortingSolution2);
	/*testInsertionSortAscending_L1();
	testInsertionSortDescending_L1();
	testInsertionSortAscending_L2();
	testInsertionSortDescending_L2();
	testInsertionSortAscending_pnum();
	testInsertionSortDescending_pnum();
	resetLists();
	testMergeSort_L1();
	testMergeSort_L2();
	testMergeSort_pnum();*/
	testProblem(problemArr1, solutionArr1, "merge", "");
	testProblem(problemArr1, solutionArr1, "insert", "asc");
	testProblem(problemArr1, solutionArr1, "insert", "desc");
	testProblem(problemArr2, solutionArr2, "merge", "");
	testProblem(problemArr2, solutionArr2, "insert", "asc");
	testProblem(problemArr2, solutionArr2, "insert", "desc");
	
}