/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_bst {
	struct node_bst* parent;
	int key;
	struct node_bst* left;	// left child
	struct node_bst* right;	// right child
} BSTNode;

BSTNode* new_node(int x);
BSTNode* insert(BSTNode* T, BSTNode* z);
void transplant(BSTNode* T, BSTNode* u, BSTNode* v);
void delete(BSTNode* T, BSTNode* z);
void inordertreewalk(BSTNode* T);
BSTNode* treemax(BSTNode* T);
BSTNode* treemin(BSTNode* T);
BSTNode* treesearch(BSTNode* z, int key);
BSTNode* successor(BSTNode* z);
BSTNode* predecessor(BSTNode* z);
int treeheight(BSTNode* T);
int treesize(BSTNode* T);
void padding(char ch, int n);
void printTree(BSTNode* T, int level);
void growTree(BSTNode* T);
void transplant(BSTNode* T, BSTNode* u, BSTNode* v);
void tree_delete(BSTNode* T, BSTNode* z);