#include "header.h"

// Creates a new node and returns a pointer to it.

Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = key;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
List* createList(int key) {
	List* newList = (List*)malloc(sizeof(List));
	newList->empty = NULL;
	newList->id = key;
	return newList;
}
void insert(List** l, Node** n) {
	int success = 0;
	printf("\nINSERTING DATA\n");
	printf("List: %i | Node pointer: %p | Data: %i \n", (*l)->id, (*n), (*n)->data);
	printf("Checking if list is empty...\n");
	if (isEmpty(l)) {
		(*l)->node = (*n);
		(*l)->empty = 1;
		printf("INSERTED Node INTO LIST: %i | POINTER: %p | Data: %i \n", (*l)->id, (*l)->node, (*l)->node->data);
	}
	else {
		(*n)->prev = (*l)->node;
		(*l)->node->next = (*n);
		printf("INSERTED Node INTO LIST: %i | POINTER: %p | Data: %i \n", (*l)->id, (*l)->node->next, (*l)->node->next->data);
	}
	
}

int isEmpty(List** l) {
	if ((*l)->empty == NULL) {
		printf("LIST IS EMPTY \n");
		return 1;
	}
	else
		return 0;
}
Node* search(List** l, int key) {
	int i = 1;
	Node* tempnode = (*l)->node;
	do {
		i++;
		if (tempnode->data == key) {
			printf("\nFOUND TEMPNODE HALLELUEJAH | Pointer(%p) -> Data(%d)\n", tempnode, tempnode->data);
			return tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	free(tempnode);
}
Node* Maximum(List** l) {
	Node* tempnode = (*l)->node;
	Node* bignode = NULL;
	int i = 0;
	int big = 0;
	do {
		i++;
		if (tempnode->data > big) {
			big = tempnode->data;
			bignode = tempnode;
		}
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	if (bignode == NULL)
		printf("\nThere are no nodes in the selected list.");
	return bignode;
}
void print(List** l) {
	int i = 1;
	Node* tempnode = (*l)->node;
	printf("\nPRINTING List: %d", (*l)->id);
	do {
		i++;
		printf("\n-----");
		printf("\n| %d |", tempnode->data);
		printf("\n-----");
		tempnode = tempnode->next;
	} while (tempnode != NULL);
	free(tempnode);
}