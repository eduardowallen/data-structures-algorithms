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
	/*
	root = insert(root, new_node(13));	// Creates a root and inserts node
	growTree();	// Inserts some nodes into tree
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
	structure(root,0);*/
	//fileToTree(root, loadProblem(1));
	growTree(root);
	printTree(root, 0);
}