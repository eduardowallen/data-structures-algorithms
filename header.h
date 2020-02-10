#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next; // Pointer to the next node
	struct Node* prev; // Pointer to the previous node
} Node;

typedef struct List {
	struct Node* node; // Pointer to the nodes inside the list
	int head;
	int id;
} List;
