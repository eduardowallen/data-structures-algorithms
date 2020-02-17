#include "header.h"

int main() {
	int i;
	List *List1, *List2;				// Creates List1 and List2
	// Creates lists L1 and L2
	Node *tempnode1, *tempnode2;		// Creates a temporary node that we can use within the main function
	List1 = createList(1);				// Allocates memory and sets its values in createList
	List2 = createList(2);				// Allocates memory and sets its values in createList

	for (i = 1; i < 10; i++) {			// Inserting 10 nodes into the list, going from 1 to 10.
		tempnode1 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
		tempnode2 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
		insert(&List1, &tempnode1);		// Inserts the created node into list 1
		insert(&List2, &tempnode2);		// Inserts the created node into list 2
	}
	for (i = 10; i > 0; i--) {			// Inserting 10 nodes into the list, going from 10 to 1.
		tempnode1 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
		tempnode2 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
		insert(&List1, &tempnode1);		// Inserts the created node into list 1
		insert(&List2, &tempnode2);		// Inserts the created node into list 2
	}
	print(&List1);						// Prints list 1
	print(&List2);						// Prints list 2
	search(&List1, 2);					// Searches list 1 for nodes that contain the key 2 and returns a pointer to the node. Does not return anything if the list is empty.
	tempnode1 = Maximum(&List1);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	tempnode2 = Minimum(&List1);		// Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode1 != NULL)
		printf("\nMaximum: data(%d), pointer(%p)", tempnode1->data, tempnode1);	// Prints the data in the node returned from Maximum function.
	if (tempnode2 != NULL)
		printf("\nMinimum: data(%d), pointer(%p)", tempnode2->data, tempnode2);	// Prints the data in the node returned from Minimum function.
}