#include "header.h"
#pragma warning (disable: 6386 6385 6011 4133 4047) // Disabling some warnings that were a nuisance.
/* TEST FUNCTIONS FOR SORTING PROBLEMS */
// arrays to use when testing the files, replace the paths with your local path for the sorting problem you want to run. Yes, we could have made this prettier...


void growTree(Node* root) {
	insert(root, new_node(5));		// Inserts node
	insert(root, new_node(3));		// Inserts node
	insert(root, new_node(4));		// Inserts node
	insert(root, new_node(50));		// Inserts node
	insert(root, new_node(49));		// Inserts node
	insert(root, new_node(12));		// Inserts node
	insert(root, new_node(11));		// Inserts node
	insert(root, new_node(42));		// Inserts node
}


