/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
	int data;					// Integer that we store the node data into
	struct node_t* next;	// Pointer to the next node
} Node;

typedef struct adjlist_t {
	Node* head;	// Pointer to the nodes inside the list
} AdjList;

typedef struct graph_t {
	int V;	// översättning: noder i grafen
	AdjList* array;
} Graph;

