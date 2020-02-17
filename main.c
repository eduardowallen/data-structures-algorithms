#include "header.h"

int main() {
	int i;
	List* List1;
	List *List2;
	// Creates lists L1 and L2
	Node* tempnode1;
	Node *tempnode2;					// Creates a temporary node that we can use within the main function
	List1 = createList(1);			// Allocates memory and sets its values in createList
	List2 = createList(2);			// Allocates memory and sets its values in createList
	for (i = 0; i < 10; i++) {
		tempnode1 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode
		tempnode2 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode
		insert(&List1, &tempnode1);		// Inserts the created node into list 1
		insert(&List2, &tempnode2);		// Inserts the created node into list 2

	}
	for (i = 10; i > 0; i--) {
		tempnode1 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode
		tempnode2 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode
		insert(&List1, &tempnode1);		// Inserts the created node into list 1
		insert(&List2, &tempnode2);		// Inserts the created node into list 2

	}
	print(&List1);					// Prints list 1
	print(&List2);					// Prints list 2
	search(&List1, 2);				// Searches list 1 for nodes that contain the key 2 and returns a pointer to the node. Does not return anything if the list is empty.
	tempnode1 = Maximum(&List1);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	tempnode2 = Minimum(&List1);
	printf("Maximum: %i", tempnode1->data);	// Prints the data returned from Maximum function.
	printf("Minimum: %i", tempnode2->data);
}