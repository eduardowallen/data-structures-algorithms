#pragma once
#include <stdio.h>
#include <math.h>

typedef struct btNode BTNode;

struct btNode {
	int key;
	int depth;
	int num;
	BTNode* parent;
	BTNode* left;
	BTNode* right;
};

typedef struct bTree {
	char name[64];
	int max_depth;
	BTNode* root;
} BTree;

BTNode* createNode(int key);

BTree* createTree();

BTNode* treeMinimum(BTNode* start_node);

BTNode* treeMaximum(BTNode* start_node);

BTNode* treeSearch(BTNode* start_node, int search_key);

BTNode* inOrderTreeWalk(BTNode* start_node, int depth);

//Error?
BTNode* treeSuccessor(BTNode* search_node);

BTNode* treePredecessor(BTNode* search_node);

void treeInsert(BTree* _tree, BTNode* insert_node);

BTNode* treeDelete(BTree* _tree, BTNode* delete_node);

int getMaxDepth(BTNode* start_node);

int rotateRight(BTree* _tree, BTNode* rotation_node);

int rotateLeft(BTree* _tree, BTNode* rotation_node);

int balanceBTree(BTree* _tree, BTNode* start_node);

void printDepthTree(BTNode* root);

void printDepth(BTNode* root, int depth);

int printTreeInOrder(BTNode* node);

int treeIsEmpty(BTree* tree);