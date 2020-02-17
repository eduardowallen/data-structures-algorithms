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
void insert(List** L, Node** N) { // Using double pointers because we want to manipulate the list and node in main function
	printf("\nTRYING TO INSERTING DATA INTO L%d\n", (*L)->id);
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
		(*N)->prev = tempnode;	// Set prev for the node n (that points to tempnode in main) to point to the newest node in the list (that origins from main)
		tempnode->next = (*N);	// Set next for the newest node in the list (that origins from main)
		printf("Inserted node into L%d\n", (*L)->id);
	}
}

int isEmpty(List** L) {
	if ((*L)->empty == NULL) {
		printf("L%d is empty.\n");
		return 1;
	}
	else return 0;
}
Node* search(List** L, int key) {
	Node* tempnode = (*L)->node;
	do {
		if (tempnode->data == key) {
			printf("\nFOUND TEMPNODE HALLELUEJAH | Pointer(%p) -> Data(%d)\n", tempnode, tempnode->data);
			return tempnode;		// Returns tempnode to main
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
}
Node* Maximum(List** L) {
	Node* tempnode = (*L)->node; // Creates a temporary node and sets its data to the List node
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
Node* Minimum(List** L) {
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
	do {
		i++;
		printf("-----\n");
		printf("| %d |\n", tempnode->data);
		printf("-----\n");
		tempnode = tempnode->next;
	} while (tempnode != NULL);
}