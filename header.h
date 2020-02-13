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
