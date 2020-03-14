/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;			// Integer that we store the node data into
	struct Node* next;	// Pointer to the next node
	struct Node* prev;	// Pointer to the previous node
} Node;

typedef struct List {
	struct Node* node;	// Pointer to the nodes inside the list
	int empty;			// Integer that we use to keep track if the list is empty or not
	int id;				// Integer that we use to see what list ID we are working with
} List;

/* Linked list functions */
Node* createNode(int key);
List* createList(int key);
void insert(List* L, Node* N);
int isEmpty(List* L);
Node* search(List* L, int key);
Node* successor(List* L, Node* N);
Node* predecessor(List* L, Node* N);
Node* maximum(List* L);
Node* minimum(List* L);
void print(List* L);
void delete(List* L, Node* N);
void Stack();
void Queue();