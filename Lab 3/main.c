/* Created by Eduardo Wallén & Junior Corazza */

#include "header.h"
#include "load_file.h"
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
/*
Det vi har kvar:
Delete
*/
/*
			 13
		   /   \
		  5     50
		 /\     /
		3 12   49
		\  /   /
		 4 11|42
*/
int main() {

	// Exercise 1
	Node* root = (Node*)malloc(sizeof(Node));
	root = NULL;
	root = insert(root, new_node(13));	// Creates a root
	growTree(root);	// Inserts some nodes into tree
	printf("Height: %d\n", treeheight(root));		// height of tree
	printf("Size: %d\n", treesize(root));			// Size of tree
	inordertreewalk(root);			// Prints every node out in order
	treemax(root);					// prints tree max
	treemin(root);					// prints tree min
	printTree(root, 0);				// Prints the tree so that it's easier to see if it looks the way we think it looks
	Node* temp = new_node(NULL);	// creates temp node to catch our tree search
	temp = treesearch(root, 13);
	printf("treesearch for 13 is: %d\n", temp->key);
	predecessor(temp);
	successor(temp);
	printf("Attempting delete on node 5\n");
	delete(root, treesearch(root, 5));
	printTree(root,0);

	// Exercise 2
	root = NULL; // Clear the tree of its contents before we start
	printf("\n\n\n----- CREATING NEW TREE BELOW ------\n\n\n");
	int problem_to_load = sortingProblem4;		// Change this to any of the char arrays (ending with ProblemX where X is a number) at the top of the document
	int solution_to_load = sortingSolution4;	// Change this to any of the char arrays (ending with SolutionX where X is a number) at the top of the document
	int* L = load_file(solution_to_load);		// Loads a file with a problem we want to create the tree with
	root = insert(root, new_node(L[1]));
	for (int i = 2; i < L[0]; i++) {
		//printf("%d ", L[i]);
		insert(root, new_node(L[i]));
	}
	//printTree(root, 0); // Use this to print the tree 
	printf("\n\n----- Now printing the tree in ascending order ------\n\n");
	inordertreewalk(root);			// Prints every node out in order
	printf("\n\n----- Now printing the solution in ascending order ------\n\n");
	int* S = load_file(solution_to_load); // Prints the solution (in order) to the problem we previously loaded
	for (int i = 1; i < S[0]; i++)
		printf("%d ", S[i]);
}