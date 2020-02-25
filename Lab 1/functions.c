#include "header.h"
// Created by Eduardo Wallén & Junior Corazza
// Creates a new node and returns a pointer to it.

Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// Allocate memory for the node
	newNode->data = key;	// Set the data to key
	newNode->prev = NULL;	// Set prev to NULL
	newNode->next = NULL;	// Set next to NULL
	return newNode;			// Returns node to the main function
}
List* createList(int key) {
	List* newList = (List*)malloc(sizeof(List));	// Allocate memory for the list
	newList->empty = NULL;	// Set empty to NULL
	newList->id = key;		// Set id to key
	return newList;			// Return the list to the main function
}
void insert(List** L, Node** N) {	// Using double pointers because we want to manipulate the list and node in main function
	printf("\nAttempting to insert node into L%d...\n", (*L)->id);
	printf("Node to insert: %p | Data: %i \n", (*N), (*N)->data);
	printf("Checking if list is empty...\n");
	if (isEmpty(L)) {				// Check if list is empty (if true, continue)
		(*L)->node = (*N);			// Insert the node n(that points to tempnode in main) to the list l (that origins from main)
		(*L)->empty = 1;			// Set the list to not being empty anymore
		printf("Inserted node as head into L%d\n", (*L)->id);
	}
	else {
		Node* tempnode = (*L)->node;
		printf("L%d is not empty. Head node is %p.\n", (*L)->id, (*L)->node);
		while (tempnode->next != NULL)
			tempnode = tempnode->next;
		printf("Tempnode is now: %p\n", tempnode);
		(*N)->prev = tempnode;		// Set prev for the node n (that points to tempnode in main) to point to the newest node in the list (that origins from main)
		tempnode->next = (*N);		// Set next for the newest node in the list (that origins from main)
		printf("Inserted node into L%d\n", (*L)->id);
	}
}
int isEmpty(List** L) {
	if ((*L)->empty == NULL) {
		printf("L%d is empty.\n", (*L)->id);
		return 1;
	}
	else return 0;
}
Node* search(List** L, int key) {
	Node* tempnode = (*L)->node;
	printf("\nSearching L%d for %d...", (*L)->id, key);
	do {
		if (tempnode->data == key) {
			printf("\nNode found in L%d: pointer(%p), data(%d)\n", (*L)->id, tempnode, tempnode->data);
			return tempnode;		// Returns tempnode to main
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	printf("\nNode not found.");
	return NULL;
}
Node* successor(List** L, Node** N) {
	Node* tempnode = (*N);
	if (tempnode->next == NULL) 
		printf("\n%p has no successor and is therefore the last node in the list.\n", (*N));
	return tempnode->next;			// Returns tempnode to main (NULL if empty)
}
Node* predecessor(List** L, Node** N) {
	Node* tempnode = (*N);
	if (tempnode->prev == NULL) 
		printf("\n%p has no predecessor and is therefore the first node in the list.\n", (*N));
	return tempnode->prev;			// Returns tempnode to main (NULL if empty)
}
Node* maximum(List** L) {
	Node* tempnode = (*L)->node;	// Creates a temporary node and sets its data to the List node
	Node* big_node = tempnode;		// Creates a temporary node and assigns its value to NULL
	int big = 0;
	do {
		if (tempnode->data > big) {
			big = tempnode->data;
			big_node = tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	if (big_node == NULL)
		printf("Maximum function response: There are no nodes in the selected list.\n");
	return big_node;
}
Node* minimum(List** L) {
	Node* tempnode = (*L)->node;	// Creates a temporary node and assigns the incoming node to it
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
void print(List** L) {
	int i = 1;
	Node* tempnode = (*L)->node;
	printf("PRINTING List: %d\n", (*L)->id);
	if (!isEmpty(L)) {
		do {
			i++;
			printf("-----\n");
			printf("| %d |\n", tempnode->data);
			printf("-----\n");
			tempnode = tempnode->next;
		} while (tempnode != NULL);
	}

}
Node* delete(List** L, Node** N) {	// Using double pointers because we want to manipulate the list and node in main function
	printf("\nAttempting to delete node from L%d...\n", (*L)->id);
	printf("Node to delete: %p | Data: %i \n", (*N), (*N)->data);
	Node* nextnode = successor(L, N);
	Node* previousnode = predecessor(L, N);

	if (previousnode == NULL && nextnode == NULL) {	// If the list only has one node
		printf("L%d will be empty after deletion.\n", (*L)->id);
		(*L)->empty = 0; // Set the list to empty
		(*L)->node = NULL;
	} else {
		if (previousnode == NULL) {			// If we are at head of list, previous should be NULL
			nextnode->prev = NULL;			// Set the next node->prev to be NULL
			(*L)->node = nextnode;			// Set the next node to be head of list
			printf("Head of list should now be %p, (%d)\n", nextnode, nextnode->data);
		} else if (nextnode == NULL) {		// If we are at end of list
			printf("End of list is now %p (%d)\n", previousnode, previousnode->data);
			previousnode->next = NULL;
		} else {							// If we inbetween nodes
			nextnode->prev = previousnode;	// Point past the current node (the next node's prev points to the node before the current node)
			previousnode->next = nextnode;	// Point past the current node (previous node's next points to the node after the current node)
			printf("We are in between nodes.\n");
			printf("previousnode is %p (%d), previousnode->next is %p, data(%d)\n", previousnode, previousnode->data, previousnode->next, previousnode->next->data);
			printf("nextnode is %p (%d), nextnode->prev is %p, data(%d)\n", nextnode, nextnode->data, nextnode->prev, nextnode->prev->data);
		}
		printf("Head of list in reality is pointer(%p), data(%d), next(%p), prev(%p)\n", (*L)->node, (*L)->node->data, (*L)->node->next, (*L)->node->prev);
	}
	return((*N));
}