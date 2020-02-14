#include "header.h"

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
	printf("\nINSERTING DATA\n");
	printf("List%i | Node pointer: %p | Data: %i \n", (*L)->id, (*N), (*N)->data);
	printf("Checking if list is empty...\n");
	if (isEmpty(L)) {				// Check if list is empty (if true, continue)
		(*L)->node = (*N);			// Insert the node n(that points to tempnode in main) to the list l (that origins from main)
		(*L)->empty = 1;			// Set the list to not being empty anymore
		printf("INSERTED Node INTO LIST: %i | POINTER: %p | Data: %i \n", (*L)->id, (*L)->node, (*L)->node->data);
	}
	else {
		(*N)->prev = (*L)->node;	// Set prev for the node n(that points to tempnode in main) to point to the newest node in the list (that origins from main)
		(*L)->node->next = (*N);	// Set next for the newest node in the list (that origins from main)
		printf("INSERTED Node INTO LIST: %i | POINTER: %p | Data: %i \n", (*L)->id, (*L)->node->next, (*L)->node->next->data);
	}
}

int isEmpty(List** L) {
	if ((*L)->empty == NULL) {
		printf("LIST IS EMPTY \n");
		return 1;
	}
	else return 0;
}
Node* search(List** L, int key) {
	Node* tempnode = (*L)->node;	// Allocate memory for a temporary node
	do {
		if (tempnode->data == key) {
			printf("\nFOUND TEMPNODE HALLELUEJAH | Pointer(%p) -> Data(%d)\n", tempnode, tempnode->data);
			return tempnode;		// Returns tempnode to main
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	free(tempnode);
}
Node* Maximum(List** L) {
	Node* tempnode = (*L)->node; // 
	Node* big_node = NULL;
	int i = 0;
	int big = 0;
	do {
		i++;
		if (tempnode->data > big) {
			big = tempnode->data;
			big_node = tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	if (big_node == NULL)
		printf("\nThere are no nodes in the selected list.");
	return big_node;
}
Node* Minimum(List** L) {
	Node* tempnode = (*L)->node; // 
	Node* min_node = NULL;
	int i = 0;
	int min = 0;
	do {
		i++;
		if (min < tempnode->data) {
			min = tempnode->data;
			min_node = tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	if (min_node == NULL)
		printf("\nThere are no nodes in the selected list.");
	return min_node;
}
void print(List** L) {
	int i = 1;
	Node* tempnode = (*L)->node;
	printf("\nPRINTING List: %d", (*L)->id);
	do {
		i++;
		printf("\n-----");
		printf("\n| %d |", tempnode->data);
		printf("\n-----");
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	free(tempnode);
}