// Written by Eduardo Wallén and Junior Corazza 2020-03-05
#include "sorting_algorithms.h"
#include "load_file.h"

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
	char sortingProblem2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-1-problem" };
	char sortingSolution2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-1-solution" };
	testProblem(load_file(sortingProblem1), load_file(sortingSolution1), "merge", "");
	testProblem(load_file(sortingProblem1), load_file(sortingSolution1), "insert", "asc");
	testProblem(load_file(sortingProblem1), load_file(sortingSolution1), "insert", "desc");
	testProblem(load_file(sortingProblem2), load_file(sortingSolution2), "merge", "");
	testProblem(load_file(sortingProblem2), load_file(sortingSolution2), "insert", "asc");
	testProblem(load_file(sortingProblem2), load_file(sortingSolution2), "insert", "desc");
	
}