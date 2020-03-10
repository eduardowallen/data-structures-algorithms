#include "header.h"
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
	Node* root = NULL;
	root = insert(root, new_node(13));	// Creates a root and inserts node
	insert(root, new_node(5));		// Inserts node
	insert(root, new_node(3));		// Inserts node
	insert(root, new_node(4));		// Inserts node
	insert(root, new_node(50));		// Inserts node
	insert(root, new_node(49));		// Inserts node
	insert(root, new_node(12));		// Inserts node
	insert(root, new_node(11));		// Inserts node
	insert(root, new_node(42));		// Inserts node
	printf("Height: %d\n", treeheight(root));		// height of tree
	printf("Size: %d\n", treesize(root));			// Size of tree
	inordertreewalk(root);			// Prints every node out in order
	treemax(root);					// prints tree max
	treemin(root);					// prints tree min
	structure(root, 0); // TREE PRINT OUT
	Node* temp = new_node(NULL);	 // creates temp node for our tree search
	temp = treesearch(root, 13);
	printf("treesearch for 13 is: %d\n", temp->key);
	predecessor(temp);
	successor(temp);
}