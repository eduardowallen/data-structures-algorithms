#include <stdio.h>
typedef struct node {
	struct Node* parent;
	int key;
	struct Node* left;	// left child
	struct Node* right; // right child
} Node;

Node* new_node(int x);
Node* insert(Node* T, Node* z);
void transplant(Node* T, Node* u, Node* v);
Node* delete(Node* T, Node* z);
void inordertreewalk(Node* root);
int treemax(Node* root);
int treemin(Node* root);
int treesearch(Node* root, int key);
int successor(Node* root);
int predecessor(Node* root);
int treeheight(Node* root);
int treesize(Node* root);
void padding(char ch, int n);
void printTree(struct node* root, int level);
void growTree(Node* root);
void fileToTree(Node* root, int arr[]);
int loadSolution(int x);
int loadProblem(int x);