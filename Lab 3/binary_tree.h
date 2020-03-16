/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t {
	struct node_t* parent;
	int key;
	struct node_t* left;	// left child
	struct node_t* right; // right child
} Node;

Node* new_node(int x);
Node* insert(Node* T, Node* z);
void transplant(Node* T, Node* u, Node* v);
void delete(Node* T, Node* z);
void inordertreewalk(Node* root);
Node* treemax(Node* root);
Node* treemin(Node* root);
Node* treesearch(Node* root, int key);
Node* successor(Node* root);
Node* predecessor(Node* root);
int treeheight(Node* root);
int treesize(Node* root);
void padding(char ch, int n);
void printTree(Node* root, int level);
void growTree(Node* root);