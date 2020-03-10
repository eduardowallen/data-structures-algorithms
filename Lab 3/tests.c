#include "header.h"

#pragma warning (disable: 6386 6385 6011 4133 4047) // Disabling some warnings that were a nuisance.
/* TEST FUNCTIONS FOR SORTING PROBLEMS */
// arrays to use when testing the files, replace the paths with your local path for the sorting problem you want to run. Yes, we could have made this prettier...
char sortingProblem1[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-1-problem" };
char sortingSolution1[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-1-solution" };
char sortingProblem2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-2-problem" };
char sortingSolution2[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-2-solution" };
char sortingProblem3[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-3-problem" };
char sortingSolution3[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-3-solution" };
char sortingProblem4[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-4-problem" };
char sortingSolution4[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-100-4-solution" };
char sortingProblem5[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-5-problem" };
char sortingSolution5[] = { "C:/Users/eduar/OneDrive/Plugg/Visual studio projects/data-structures-algorithms/Lab 2/sorting_problems/test-10-5-solution" };
int loadSolution(int x) {
	int* solutionArr1 = load_file(sortingSolution1);
	int* solutionArr2 = load_file(sortingSolution2);
	int* solutionArr3 = load_file(sortingSolution3);
	int* solutionArr4 = load_file(sortingSolution4);
	int* solutionArr5 = load_file(sortingSolution5);
	switch (x) {
	case 1:
		return solutionArr1;
		break;
	case 2:
		return solutionArr2;
		break;
	case 3:
		return solutionArr3;
		break;
	case 4:
		return solutionArr4;
		break;
	case 5:
		return solutionArr5;
		break;
	}
	return 0;
}
int loadProblem(int x) {
	int* problemArr1 = load_file(sortingProblem1);
	int* problemArr2 = load_file(sortingProblem2);
	int* problemArr3 = load_file(sortingProblem3);
	int* problemArr4 = load_file(sortingProblem4);
	int* problemArr5 = load_file(sortingProblem5);

	switch (x) {
		case 1:
			return problemArr1;
			break;
		case 2:
			return problemArr2;
			break;
		case 3:
			return problemArr3;
			break;
		case 4:
			return problemArr4;
			break;
		case 5:
			return problemArr5;
			break;
	}
	return 0;
}
void growTree(Node* root) {
	insert(root, new_node(13));		// Inserts node
	insert(root, new_node(5));		// Inserts node
	insert(root, new_node(3));		// Inserts node
	insert(root, new_node(4));		// Inserts node
	insert(root, new_node(50));		// Inserts node
	insert(root, new_node(49));		// Inserts node
	insert(root, new_node(12));		// Inserts node
	insert(root, new_node(11));		// Inserts node
	insert(root, new_node(42));		// Inserts node
}

/*
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
			insertionSort(arr, start + 1, 0);		// Using insertionSort on the incoming array
	}
	if (strcmp(type, "merge") == 0) {
		printf("Mergesort on problem\n");
		mergeSort(arr, 0, start); // Using mergeSort algorithm on the incoming array
		print(arr, start + 1);
		printf("Solution:\n");
		print(solution, solution[0] + 1);
	}
	printf("End of test\n\n");
}*/