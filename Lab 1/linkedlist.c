/* Created by Eduardo Wallén & Junior Corazza */
#include "linkedlist.h"

// Creates a new node and returns a pointer to it.
Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// Allocate memory for the node
	if (newNode == NULL) {
		printf("Could not allocate memory for the node.");
		return 1;
	}
	newNode->data = key;	// Set the data to key
	newNode->prev = NULL;	// Set prev to NULL
	newNode->next = NULL;	// Set next to NULL
	return newNode;			// Returns the node
}
List* createList(int key) {
	List* newList = (List*)malloc(sizeof(List));	// Allocate memory for the list
	if (newList == NULL) {
		printf("Could not allocate memory for the list.");
		return 1;
	}
	newList->empty = 0;		// Set empty to 0
	newList->id = key;		// Set id to key
	return newList;			// Return the list
}
void insert(List* L, Node* N) {	// Using double pointers because we want to manipulate the list and node in main function
	//printf("\nAttempting to insert node into L%d...\n", L->id);
	//printf("Node to insert: %p | Data: %i \n", N, N->data);
	//printf("Checking if list is empty...\n");
	if (isEmpty(L)) {			// Check if list is empty (if true, continue)
		L->node = N;			// Insert the node n(that points to tempnode in main) to the list l (that origins from main)
		L->empty = 1;			// Set the list to not being empty anymore
		printf("Inserted node %d as head into L%d\n", N->data, L->id);
	}
	else {
		Node* tempnode = L->node;
		//printf("L%d is not empty. Head node is %p.\n", L->id, L->node);
		while (tempnode->next != NULL)
			tempnode = tempnode->next;
		//printf("Tempnode is now: %p\n", tempnode);
		N->prev = tempnode;		// Set prev for the node n (that points to tempnode in main) to point to the newest node in the list (that origins from main)
		tempnode->next = N;		// Set next for the newest node in the list (that origins from main)
		printf("Inserted node %d into L%d\n", N->data, L->id);
	}
}
int isEmpty(List* L) {
	if (L->empty == 0) {
		printf("L%d is empty.\n", L->id);
		return 1;
	}
	else return 0;
}
Node* search(List* L, int key) {
	Node* tempnode = L->node;
	do {
		if (tempnode->data == key) {
			return tempnode;		// Returns tempnode
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	printf("\nNode not found.");
	return NULL;
}
Node* successor(List* L, Node* N) {
	Node* head = L->node, * successor = (Node*)malloc(sizeof(Node));
	successor->data = 0;
	while (successor->data < N->data && head != NULL) {
		if (head->data > N->data)
			successor = head;
		head = head->next;
	}
	head = L->node;
	while (head != NULL) {
		if (head->data > N->data && successor->data > head->data)
			successor = head;
		head = head->next;
	}
	if (successor->data != 0)
		return successor;			// Returns successor (NULL if empty)
	else return NULL;
}
Node* predecessor(List* L, Node* N) {
	Node* head = L->node, * predecessor = (Node*)malloc(sizeof(Node));
	predecessor->data = 0;
	while (head != NULL) {
		if (head->data < N->data && head->data > predecessor->data)
			predecessor = head;
		head = head->next;
	}
	if (predecessor->data != 0)
		return predecessor;			// Returns predecessor (NULL if empty)
	else return NULL;
}
Node* maximum(List* L) {
	Node* tempnode = L->node;	// Creates a temporary node and sets its data to the List node
	Node* big_node = tempnode;		// Creates a temporary node and assigns its value to NULL
	int big = tempnode->data;
	do {
		if (big < tempnode->data) {
			big = tempnode->data;
			big_node = tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	if (big_node == NULL)
		printf("Maximum function response: There are no nodes in the selected list.\n");
	return big_node;
}
Node* minimum(List* L) {
	Node* tempnode = L->node;	// Creates a temporary node and assigns the incoming node to it
	Node* min_node = tempnode;		// Creates a temporary node and assigns its value to NULL
	int min = tempnode->data;
	do {
		if (min > tempnode->data) {
			min = tempnode->data;
			min_node = tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	if (min_node == NULL)
		printf("Minimum function response: There are no nodes in the selected list.\n");
	return min_node;
}
void print(List* L) {
	int i = 1;
	Node* tempnode = L->node;
	printf("\n     ");
	if (!isEmpty(L)) {
		do {
			i++;
			printf("-----");
			tempnode = tempnode->next;
		} while (tempnode != NULL);
		tempnode = L->node;
		i = 1;
		printf("\nHEAD ");
		do {
			i++;
			printf("| %d ", tempnode->data);
			tempnode = tempnode->next;
		} while (tempnode != NULL);
		printf("| TAIL\n     ");
		for (int j = 1; j < i; j++) 
			printf("-----");
		printf("\n");
	}

}
void delete(List* L, Node* N) {
	printf("\nAttempting to delete node from L%d...\n", L->id);
	//printf("Node to delete: %p | Data: %i \n", N, N->data);
	Node* nextnode = N->next;
	Node* previousnode = N->prev;

	if (previousnode == NULL && nextnode == NULL) {	// If the list only has one node
		printf("L%d will be empty after deletion.\n", L->id);
		L->empty = 0; // Set the list to empty
		L->node = NULL;
	}
	else {
		if (previousnode == NULL) {			// If we are at head of list, previous should be NULL
			nextnode->prev = NULL;			// Set the next node->prev to be NULL
			L->node = nextnode;			// Set the next node to be head of list
			//printf("Head of list should now be %p, (%d)\n", nextnode, nextnode->data);
		}
		else if (nextnode == NULL) {		// If we are at end of list
			//printf("End of list is now %p (%d)\n", previousnode, previousnode->data);
			previousnode->next = NULL;
		}
		else {							// If we inbetween nodes
			nextnode->prev = previousnode;	// Point past the current node (the next node's prev points to the node before the current node)
			previousnode->next = nextnode;	// Point past the current node (previous node's next points to the node after the current node)
			//printf("We are in between nodes.\n");
			//printf("previousnode is %p (%d), previousnode->next is %p, data(%d)\n", previousnode, previousnode->data, previousnode->next, previousnode->next->data);
			//printf("nextnode is %p (%d), nextnode->prev is %p, data(%d)\n", nextnode, nextnode->data, nextnode->prev, nextnode->prev->data);
		}
		//printf("Head of list in reality is pointer(%p), data(%d), next(%p), prev(%p)\n", L->node, L->node->data, L->node->next, L->node->prev);
	}
	printf("Node %p deleted.", N);
	free(N);
}