#include <stdio.h>
typedef struct node {
	struct Node* parent;
	int key;
	struct Node* left;	// left child
	struct Node* right; // right child

} Node;