#include "header.h"

int main() {
	List* List1, *List2;			// Create pointer arrays for lists L1 and L2
	Node* tempnode;					// Create a temporary node that we can use within the main function
	List1 = createList(1);			// Create L1 and L2
	List2 = createList(2);
	tempnode = createNode(1);		// Creates a node and stores it in tempnode
	insert(&List1, &tempnode);		// Inserts the created node into list 1
	insert(&List2, &tempnode);		// Inserts the created node into list 2
	tempnode = createNode(2);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode
	insert(&List1, &tempnode);		// Inserts the created node into list 1
	insert(&List2, &tempnode);		// Inserts the created node into list 2
	print(&List1);					// Prints list 1
	print(&List2);					// Prints list 2
	search(&List1, 2);				// Searches list 1 for nodes that contain the key 2 and returns a pointer to the node. Does not return anything if the list is empty.
	tempnode = Maximum(&List1);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.

	printf("Maximum: %i", tempnode->data);	// Prints the data returned from Maximum function.
}