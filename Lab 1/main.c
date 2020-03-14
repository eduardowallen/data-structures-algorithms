/* Created by Eduardo Wallén & Junior Corazza */
#include "linkedlist.h"
int main() {
	List* L1, * L2;	// Create pointers to L1 and L2

	// Create lists L1 and L2
	L1 = createList(1);		// Allocate memory and sets its values in createList
	L2 = createList(2);		// Allocate memory and sets its values in createList

	// Create the content for L1 as described in the lab exercise 2 (L1 = [3,1,5,10,8,7]) and prints the list for overview
	insert(L1, createNode(3));insert(L1, createNode(1));insert(L1, createNode(5));insert(L1, createNode(10));insert(L1, createNode(8));insert(L1, createNode(7));print(L1);

	// Exercise 2, minimum and maximum of L1
	if (minimum(L1) != NULL) // Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
		printf("Minimum node: data(%d), pointer(%p)\n", minimum(L1)->data, minimum(L1));
	if (maximum(L1) != NULL) // Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
		printf("Maximum node: data(%d), pointer(%p)\n", maximum(L1)->data, maximum(L1));

	// Exercise 2, successor and predecessor of 5 in L1
	if (successor(L1, search(L1, 5)) != NULL)
		printf("Successor of node %p is %p where the successor data is %d\n", search(L1, 5), successor(L1, search(L1, 5)), successor(L1, search(L1, 5))->data);
	else printf("There is no successor of node %p\n", search(L1, 5));
	if (predecessor(L1, search(L1, 5)) != NULL)
		printf("Predecessor of node %p is %p where the predecessor data is %d\n", search(L1, 5), predecessor(L1, search(L1, 5)), predecessor(L1, search(L1, 5))->data);
	else printf("There is no predecessor of node %p\n", search(L1, 5));
	
	// Creates the content for L2 as described in the lab exercise 2 (L2 = [5,2,9,6,1,2]) and prints the list for overview
	insert(L2, createNode(5));insert(L2, createNode(2));insert(L2, createNode(9));insert(L2, createNode(6));insert(L2, createNode(1));insert(L2, createNode(2));print(L2);

	// Exercise 2, minimum and maximum of L2
	// Searches the list for the smallest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (minimum(L2) != NULL)
		printf("Minimum node: data(%d), pointer(%p)\n", minimum(L2)->data, minimum(L2));
	// Searches the list for the largest key and returns a pointer to the node. If the list is empty the function will return a printf.
	if (maximum(L2) != NULL)
		printf("Maximum node: data(%d), pointer(%p)\n", maximum(L2)->data, maximum(L2));	// Prints the data in the node returned from maximum function.

	// Exercise 2, successor and predecessor of 9 in L2
	if (successor(L2, search(L2, 9)) != NULL)
		printf("Successor of node %p is %p where the successor data is %d\n", search(L2, 9), successor(L2, search(L2, 9)), successor(L2, search(L2, 9))->data);
	else printf("There is no successor of node %p\n", search(L2, 9));
	if (predecessor(L2, search(L2, 9)) != NULL)
		printf("Predecessor of node %p is %p where the predecessor data is %d\n", search(L2, 9), predecessor(L2, search(L2, 9)), predecessor(L2, search(L2, 9))->data);
	else printf("There is no predecessor of node %p\n", search(L2, 9));

	// Key of predecessor in L2 of the maximum of L1
	if (maximum(L1) != NULL) {
		if (predecessor(L2, maximum(L1)) != NULL)
			printf("Predecessor of the maxmimum in L1 (node %p) of L2 is %p where the predecessor data is %d\n", maximum(L1), predecessor(L2, maximum(L1)), predecessor(L2, maximum(L1))->data);
		else printf("There is no predecessor in L2 of the maximum key in L1\n");
	}
	// Key of predecessor in L1 of the maximum of L2
	if (maximum(L2) != NULL) {
		if (predecessor(L1, maximum(L2)) != NULL)
			printf("Predecessor of the maxmimum in L1 (node %p) of L2 is %p where the predecessor data is %d\n", maximum(L2), predecessor(L1, maximum(L2)), predecessor(L1, maximum(L2))->data);
		else printf("There is no predecessor in L1 of the maximum key in L2\n");
	}
	
	// The following part of the code is used to show that the delete function works as intended.
	printf("\n\n***************************************************\n");
	printf("****  Bonus exercise, delete function (on L1)  ****\n");
	printf("***************************************************\n");
	if (search(L1, 3) != NULL) delete(L1, search(L1, 3)); print(L1);
	if (search(L1, 5) != NULL) delete(L1, search(L1, 5)); print(L1);
	if (search(L1, 1) != NULL) delete(L1, search(L1, 1)); print(L1);
	if (search(L1, 7) != NULL) delete(L1, search(L1, 7)); print(L1);
	if (search(L1, 8) != NULL) delete(L1, search(L1, 8)); print(L1);
	if (search(L1, 10) != NULL) delete(L1, search(L1, 10)); print(L1);
	
	// Queue
	printf("\nTesting queue functions\n");
	Queue();

	// Stack
	printf("\nTesting stack functions\n");
	Stack();
	
}