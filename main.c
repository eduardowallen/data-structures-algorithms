#include "header.h"

int main() {
	List *L1, *L2;				// Creates L1 and L2
	// Creates lists L1 and L2
	Node *tempnode1, *tempnode2;		// Creates a temporary node that we can use within the main function
	L1 = createList(1);				// Allocates memory and sets its values in createList
	L2 = createList(2);				// Allocates memory and sets its values in createList
	// Creates the content for L1 as described in the lab exercise 2 (L1 = [3,1,5,10,8,7])
	printf("*********************************************************************************************************\n");
	printf("*******  Creates the content for L1 as described in the lab exercise 2 (L1 = [3, 1, 5, 10, 8, 7])  ******\n");
	printf("*********************************************************************************************************\n");
	tempnode1 = createNode(3);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
	insert(&L1, &tempnode1);		// Inserts the created node into L1
	tempnode1 = createNode(1);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
	insert(&L1, &tempnode1);		// Inserts the created node into L1
	tempnode1 = createNode(5);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
	insert(&L1, &tempnode1);		// Inserts the created node into L1
	tempnode1 = createNode(10);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
	insert(&L1, &tempnode1);		// Inserts the created node into L1
	tempnode1 = createNode(8);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
	insert(&L1, &tempnode1);		// Inserts the created node into L1
	tempnode1 = createNode(7);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
	insert(&L1, &tempnode1);		// Inserts the created node into L1

	// Exercise 2, minimum and maximum of L1
	printf("\n\n*****************************************\n");
	printf("******  Exercise 2, minimum of L1  ******\n");
	printf("*****************************************\n");
	tempnode1 = Minimum(&L1);		// Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode1 != NULL)
		printf("Minimum node: data(%d), pointer(%p)\n", tempnode1->data, tempnode1);	// Prints the data in the node returned from Minimum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("******  Exercise 2, maximum of L1  ******\n");
	printf("*****************************************\n");
	tempnode1 = Maximum(&L1);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode1 != NULL)
		printf("Maximum node: data(%d), pointer(%p)\n", tempnode1->data, tempnode1);	// Prints the data in the node returned from Maximum function.
	printf("*****************************************\n");

	// Creates the content for L2 as described in the lab exercise 2 (L2 = [5,2,9,6,1,2])
	printf("\n\n\n*********************************************************************************************************\n");
	printf("*******  Creates the content for L2 as described in the lab exercise 2  (L2 = [5, 2, 9, 6, 1, 2])  ******\n");
	printf("*********************************************************************************************************\n");

	tempnode2 = createNode(5);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
	insert(&L2, &tempnode2);		// Inserts the created node into L2
	tempnode2 = createNode(2);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
	insert(&L2, &tempnode2);		// Inserts the created node into L2
	tempnode2 = createNode(9);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
	insert(&L2, &tempnode2);		// Inserts the created node into L2
	tempnode2 = createNode(6);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
	insert(&L2, &tempnode2);		// Inserts the created node into L2
	tempnode2 = createNode(1);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
	insert(&L2, &tempnode2);		// Inserts the created node into L2
	tempnode2 = createNode(2);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
	insert(&L2, &tempnode2);		// Inserts the created node into L2

	// Exercise 2, minimum and maximum of L2
	printf("\n\n*****************************************\n");
	printf("******  Exercise 2, minimum of L2  ******\n");
	printf("*****************************************\n");
	tempnode2 = Minimum(&L2);		// Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode2 != NULL)
		printf("Minimum node: data(%d), pointer(%p)\n", tempnode2->data, tempnode2);	// Prints the data in the node returned from Minimum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("******  Exercise 2, maximum of L2  ******\n");
	printf("*****************************************\n");
	tempnode2 = Maximum(&L2);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode2 != NULL)
		printf("Maximum node: data(%d), pointer(%p)\n", tempnode2->data, tempnode2);	// Prints the data in the node returned from Maximum function.
	printf("*****************************************\n");

	/*
	for (i = 1; i < 10; i++) {			// Inserting 10 nodes into the list, going from 1 to 10.
		tempnode1 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
		tempnode2 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
		insert(&L1, &tempnode1);		// Inserts the created node into L1
		insert(&L2, &tempnode2);		// Inserts the created node into L2
	}
	for (i = 10; i > 0; i--) {			// Inserting 10 nodes into the list, going from 10 to 1.
		tempnode1 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode1
		tempnode2 = createNode(i);		// Creates a node (overwrites the current data in tempnode) and stores it in tempnode2
		insert(&L1, &tempnode1);		// Inserts the created node into L1
		insert(&L2, &tempnode2);		// Inserts the created node into L2
	}
	*/
	//print(&L1);						// Prints L1 (for viewing purposes)
	//print(&L2);						// Prints L2 (for viewing purposes)

	//search(&L1, 2);					// Searches L1 for nodes that contain the key 2 and returns a pointer to the node. Does not return anything if the list is empty.
}