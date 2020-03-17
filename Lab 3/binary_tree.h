/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t {
	struct node_t* parent;
	int key;
	struct node_t* left;	// left child
	struct node_t* right;	// right child
} Node;

Node* new_node(int x);
Node* insert(Node* T, Node* z);
void transplant(Node* T, Node* u, Node* v);
void delete(Node* T, Node* z);
void inordertreewalk(Node* T);
Node* treemax(Node* T);
Node* treemin(Node* T);
Node* treesearch(Node* z, int key);
Node* successor(Node* z);
Node* predecessor(Node* z);
int treeheight(Node* T);
int treesize(Node* T);
void padding(char ch, int n);
void printTree(Node* T, int level);
void growTree(Node* T);
void transplant(Node* T, Node* u, Node* v);
void tree_delete(Node* T, Node* z);