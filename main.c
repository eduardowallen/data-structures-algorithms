#include "header.h"
// Declaring these two functions here to avoid the compiler thinking they should return integers.
Node* createNode(int key);
List* createList(int key);
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
	tempnode1 = minimum(&L1);		// Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode1 != NULL)
		printf("Minimum node: data(%d), pointer(%p)\n", tempnode1->data, tempnode1);	// Prints the data in the node returned from Minimum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("******  Exercise 2, maximum of L1  ******\n");
	printf("*****************************************\n");
	tempnode1 = maximum(&L1);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode1 != NULL)
		printf("maximum node: data(%d), pointer(%p)\n", tempnode1->data, tempnode1);	// Prints the data in the node returned from maximum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("*****  Exercise 2, successor of L1  *****\n");
	printf("*****************************************\n");
	tempnode2 = search(&L1, 5);
	tempnode1 = successor(&L1, &tempnode2);
	if (tempnode1 != NULL)
		printf("Successor of node %p is %p\n", tempnode2, tempnode1);	// Prints the data in the node returned from maximum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("****  Exercise 2, predecessor of L1  ****\n");
	printf("*****************************************\n");
	tempnode2 = search(&L1, 5);
	tempnode1 = predecessor(&L1, &tempnode2);
	if (tempnode1 != NULL)
		printf("Predecessor of node %p is %p\n", tempnode2, tempnode1);	// Prints the data in the node returned from maximum function.
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
	tempnode2 = minimum(&L2);		// Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode2 != NULL)
		printf("Minimum node: data(%d), pointer(%p)\n", tempnode2->data, tempnode2);	// Prints the data in the node returned from Minimum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("******  Exercise 2, maximum of L2  ******\n");
	printf("*****************************************\n");
	tempnode2 = maximum(&L2);		// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (tempnode2 != NULL)
		printf("maximum node: data(%d), pointer(%p)\n", tempnode2->data, tempnode2);	// Prints the data in the node returned from maximum function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("*****  Exercise 2, successor of L2  *****\n");
	printf("*****************************************\n");
	tempnode2 = search(&L2, 9);
	tempnode1 = successor(&L2, &tempnode2);
	if (tempnode1 != NULL)
		printf("Successor of node %p is %p\n", tempnode2, tempnode1);	// Prints the data in the node returned from predecessor function.
	printf("*****************************************\n");

	printf("\n\n*****************************************\n");
	printf("****  Exercise 2, predecessor of L2  ****\n");
	printf("*****************************************\n");
	tempnode2 = search(&L2, 9);
	tempnode1 = predecessor(&L2, &tempnode2);
	if (tempnode1 != NULL)
		printf("Predecessor of node %p is %p\n", tempnode2, tempnode1);	// Prints the data in the node returned from predecessor function.
	printf("*****************************************\n");

	// Key of predecessor in L2 of the maximum of L1
	printf("\n\n***************************************************************************\n");
	printf("*****  Exercise 2, key of the predecessor in L2 of the maximum in L1  *****\n");
	printf("***************************************************************************\n");
	tempnode2 = maximum(&L1);
	tempnode1 = maximum(&L2);
	if (tempnode2 != NULL) {
		if (tempnode2->data > tempnode1->data)
			printf("The predecessor in L2 is node(%p)->data(%d)", tempnode1, tempnode1->data);
		if (tempnode2->data < tempnode1->data)
			printf("There is no predecessor in L2 of the maximum key in L1.");
	}
	// Key of predecessor in L1 of the maximum of L2
	printf("\n\n***************************************************************************\n");
	printf("*****  Exercise 2, key of the predecessor in L1 of the maximum in L2  *****\n");
	printf("***************************************************************************\n");
	tempnode2 = maximum(&L2);
	tempnode1 = maximum(&L1);
	if (tempnode2 != NULL) {
		if (tempnode2->data > tempnode1->data)
			printf("The predecessor in L2 is node(%p)->data(%d)", tempnode1, tempnode1->data);
		if (tempnode2->data < tempnode1->data)
			printf("There is no predecessor in L1 of the maximum key in L2.");
	}

	// The following part of the code is used to show that the delete function works as intended.
	printf("\n\n***************************************************\n");
	printf("****  Bonus exercise, delete function (on L1)  ****\n");
	printf("***************************************************\n");
	tempnode2 = search(&L1, 3); if (tempnode2 != NULL) tempnode2 = delete(&L1, &tempnode2); print(&L1);
	tempnode2 = search(&L1, 5); if (tempnode2 != NULL) tempnode2 = delete(&L1, &tempnode2); print(&L1);
	tempnode2 = search(&L1, 1); if (tempnode2 != NULL) tempnode2 = delete(&L1, &tempnode2); print(&L1);
	tempnode2 = search(&L1, 7); if (tempnode2 != NULL) tempnode2 = delete(&L1, &tempnode2); print(&L1);
	tempnode2 = search(&L1, 8); if (tempnode2 != NULL) tempnode2 = delete(&L1, &tempnode2); print(&L1);
	tempnode2 = search(&L1, 10); if (tempnode2 != NULL) tempnode2 = delete(&L1, &tempnode2); print(&L1);
}