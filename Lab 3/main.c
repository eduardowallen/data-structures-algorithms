/* Created by Eduardo Wallén & Junior Corazza */

#include "binary_tree.h"
#include "load_file.h"

// Some variables that contain the search path to our solutions. Replace the part up til' "/sorting_problems" to point to your local path of the folder
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
			 13
		   /    \
		  5      50
		/  \     /
	   3   12   49
	   \   /   /
	    4 11  42
*/

int main() {

	/* 
		Exercise 1
	*/
	Node* root;
	root = NULL;
	root = insert(root, new_node(13));	// Creates a root
	growTree(root);						// Inserts some nodes into tree
	printf("Height: %d\n", treeheight(root));		// Height of tree
	printf("Size: %d\n", treesize(root));			// Size of tree
	inordertreewalk(root);			// Prints every node out in order
	treemax(root);					// prints tree max
	treemin(root);					// prints tree min
	printTree(root, 0);				// Prints the tree so that it's easier to see if it looks the way we think it looks
	Node* temp;						// creates temp node to catch our tree search
	temp = treesearch(root, 13);
	printf("treesearch for 13 is: %d\n", temp->key);
	predecessor(temp);
	successor(temp);
	printf("Attempting delete on node 5\n");
	delete(root, treesearch(root, 5));
	printTree(root,0);

	/* 
		Exercise 2 (we're using test-10-1-problem and test-10-1-solution in the following examples 
	*/
	tree_delete(root, root); // Clear the tree of its contents before we start
	printf("\n\n\n----- CREATING NEW TREE BELOW FROM LOADED FILE ------\n\n\n");
	int* L = load_file(sortingProblem1);		// Loads a file with a problem we want to create the tree with
	root = insert(root, new_node(L[1]));
	for (int i = 2; i <= L[0]; i++) {
		insert(root, new_node(L[i]));
	}
	printTree(root, 0);		// Print the tree
	printf("\n\n----- Now printing the tree in ascending order ------\n\n");
	inordertreewalk(root);	// Prints every node out in order
	
	// Print the solution (in asc order) to the problem we previously loaded
	printf("\n\n----- Now printing the solution in ascending order ------\n\n");
	int* S = load_file(sortingSolution1);
	for (int i = 1; i <= S[0]; i++)
		printf("%d ", S[i]);
	printf("\n---------------------------------------------------------\n\n");
	
	Node* p_node = predecessor(treesearch(root, 72));
	Node* s_node = successor(treesearch(root, 72));
	printf("Searching for predecessor and successor of node key 72\n");
	printf("Predecessor: %d\n", p_node->key);
	printf("Successor: %d\n", s_node->key);
	printf("Deleting predecessor %d and successor %d\n", p_node->key, s_node->key);
	delete(root, p_node);
	delete(root, s_node);
	printf("Printing tree...\n");
	printTree(root, 0);		// Print the tree
	p_node = predecessor(treesearch(root, 72));
	s_node = successor(treesearch(root, 72));
	printf("Searching for predecessor and successor of node key 72\n");
	printf("Predecessor: %d\n", p_node->key);
	printf("Successor: %d\n", s_node->key);
}