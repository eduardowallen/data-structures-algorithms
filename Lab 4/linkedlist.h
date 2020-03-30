/* Created by Eduardo Wallén & Junior Corazza */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
	float weight;
	int key;		// Integer that we store the data into
	LNode* next;	// Pointer to the next node
	LNode* prev;	// Pointer to the previous node
} LNode;

typedef struct list_t {
	LNode* sentinel;	// Pointer to the nodes inside the list
} List;

/* Linked list functions */
LNode* createNode(int key);
LNode* deleteNode(List* L, LNode* N);
List* createList(int* arr, int size);
bool free_list(List* L);
bool insertNode(List* L, LNode* N);
bool isEmpty(List* L);
LNode* searchList(List* L, int searchkey);
LNode* successorNode(List* L, LNode* N);
LNode* predecessorNode(List* L, LNode* N);
LNode* maximumNode(List* L);
LNode* minimumNode(List* L);
void printList(List* L);
int getListSize(List* L);