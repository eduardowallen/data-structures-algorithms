/* Created by Eduardo Wallén & Junior Corazza */
#include "linkedlist.h"


/* ------------------------ CREATE FUNCTIONS START ------------------------ */

// Creates a new node and returns a pointer to it.
LNode* createNode(int key) {
	LNode* newNode = malloc(sizeof(LNode));	// Allocate memory for the node
	if (newNode == NULL) {
		printf("Could not allocate memory for createNode(%d).", key);
		return NULL;
	}
	newNode->key = key;		// Set the data to key
	newNode->weight = 1;	// Set the weight to 1 as all weights will be the same
	newNode->prev = NULL;	// Set prev to NULL
	newNode->next = NULL;	// Set next to NULL
	return newNode;			// Returns the node
}
// Creates a new list and returns a pointer to it.
List* createList(int* arr, int size) {
	List* newList = malloc(sizeof(List));
	if (newList != NULL) {
		newList->sentinel = malloc(sizeof(LNode));
		if (newList->sentinel != NULL) {
			newList->sentinel->key = 666;
			newList->sentinel->next = newList->sentinel;
			newList->sentinel->prev = newList->sentinel;
		}
		else {
			printf("Memory for the linked list could not be allocated.\n");
			return NULL;
		}
	}
	else if (arr && size > 0) {
		LNode* tempnode;
		for (int i = 0; i < size; i++) {
			tempnode = createNode(arr[i]);
			if (tempnode != NULL)
				insertNode(newList, tempnode);
			else
				return NULL;
		}
	}
	return newList;
}
/* ------------------------- CREATE FUNCTIONS END ------------------------- */


/* ------------------------- OPERATION SETS START ------------------------- */

/*	
	Inserts a node at the beginning of the list
	Places the new node between the sentinel and the first node in the list
	If this is the first node, both the previous and next links point at the sentinel
*/
bool insertNode(List* L, LNode* N) {
	N->next = L->sentinel->next;
	L->sentinel->next->prev = N;
	L->sentinel->next = N;
	N->prev = L->sentinel;
	return true;
}
// Deletes a node from a list. We're returning the node in case we want to use it before freeing it from the memory.
LNode* deleteNode(List* L, LNode* N) {
	if (N != NULL) {
		N->prev->next = N->next;
		N->next->prev = N->prev;
		return N;
	}
	return NULL;
}
/* 
	Searches the list for the first matching key
	Traverses the list (from the sentinel to the next node in the list), 
	tries to match the searchkey and stops when it does so or until it returns back to the sentinel
*/
LNode* searchList(List* L, int searchkey) {
	if (getListSize(L) == 0)
		return NULL;
	LNode* tempnode = L->sentinel->next;
	while (tempnode != L->sentinel) {
		if (tempnode->key == searchkey)
			return tempnode;
		tempnode = tempnode->next;
	}
	return NULL;
}
// Returns the closest larger number in the list
LNode* successorNode(List* L, LNode* N) {
	LNode* successor = maximumNode(L);
	if (successor == N)
		return NULL;
	LNode* tempnode = L->sentinel->next;
	while (tempnode != L->sentinel) {
		if (tempnode->key > N->key && tempnode->key < successor->key)
			successor = tempnode;
		tempnode = tempnode->next;
	}
	return successor;
}
// Returns the closest smaller number to N in the list
LNode* predecessorNode(List* L, LNode* N) {
	LNode* predecessor = minimumNode(L);
	if (predecessor == N)
		return predecessor;
	LNode* tempnode = L->sentinel->next;
	while (tempnode != L->sentinel) {
		if (tempnode->key < N->key && tempnode->key > predecessor->key)
			predecessor = tempnode;
		tempnode = tempnode->next;
	}
	return predecessor;
}
/*
	Returns the node with the largest value in the list
	Traverses the list (from the sentinel to the next node in the list) 
	until it returns to the sentinel and then returns the highest value found
*/
LNode* maximumNode(List* L) {
	LNode* tempnode = L->sentinel->next;
	LNode* max_node = tempnode;
	while (tempnode != L->sentinel) {
		if (tempnode->key > max_node->key)
			max_node = tempnode;
		tempnode = tempnode->next;
	} return max_node;
}
/*
	Returns the node with the lowest value in the list
	Traverses the list (from the sentinel to the next node in the list)
	until it returns to the sentinel and then returns the lowest value found
*/
LNode* minimumNode(List* L) {
	LNode* tempnode = L->sentinel->next;
	LNode* min_node = tempnode;
	while (tempnode != L->sentinel) {
		if (tempnode->key < min_node->key)
			min_node = tempnode;
		tempnode = tempnode->next;
	} return min_node;
}
/* ------------------------- OPERATION SETS END ------------------------- */


/* -------------------- OTHER HANDY FUNCTIONS TO USE BELOW -------------------- */

// Checks if the list is empty by checking if the sentinel is pointing towards itself
bool isEmpty(List* L) {
	return L->sentinel->next == L->sentinel;
}
bool free_list(List* L) {
	if (L != NULL) {
		LNode* tempnode = L->sentinel->next;
		while (tempnode != L->sentinel) {
			tempnode = tempnode->next;
			if (tempnode->prev)
				free(tempnode->prev);
		}
		free(L);
		return true;
	} else return false;
}
int getListSize(List* L) {
	if (L == NULL)
		return 0;
	LNode* N = L->sentinel;
	int num_nodes = 0;
	while (N->next != L->sentinel) {
		num_nodes++;
		N = N->next;
	}
	return num_nodes;
}
void printList(List* L) {
	if (!isEmpty(L)) {
		int i = 1;
		LNode* tempnode = L->sentinel->next;
		printf("\n     ");
			do {
				i++;
				printf("-----");
				tempnode = tempnode->next;
			} while (tempnode != L->sentinel);
			tempnode = L->sentinel;
			i = 1;
			printf("\nHEAD ");
			do {
				i++;
				printf("| %d ", tempnode->key);
				tempnode = tempnode->next;
			} while (tempnode != L->sentinel);
			printf("| TAIL\n     ");
			for (int j = 1; j < i; j++) 
				printf("-----");
			printf("\n");
	} else printf("Could not print list (it's empty).");
}