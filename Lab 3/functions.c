#include "header.h"

Node* new_node(int x) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->key = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* T, Node* z) {
	Node* y = new_node(NULL);
	Node* x = new_node(NULL);
	y = NULL;
	x = T;
	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		T = z; // tree T was empty
	else if (z->key < y->key)
		y->left = z;
	else y->right = z;
}

void inordertreewalk(Node* root) {		// print out tree in the correct order
	if (root != NULL) {
		inordertreewalk(root->left);			// Goes through left side
		printf("%d\n", root->key);
		inordertreewalk(root->right);			// Goes through right side
	}
}
int treemax(Node* root) {

	while (root->right != NULL)
		root = root->right;
	return root;
	//printf("Max: %d\n", root->key);
}
int treemin(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
	//printf("Min: %d\n", root->key);
}

int treesearch(Node* root, int key) {
	if ((root == NULL) || (root->key == key))
		return root;
	if (root->key > key)
		return treesearch(root->left, key);
	return treesearch(root->right, key);

}

int successor(Node* root) {
	Node* temp = new_node(NULL);
	if (root->right != NULL) {
		temp = treemin(root->right);
		return printf("Successor of %d is %d \n", root->key, temp->key);
	}
	temp = root->parent;
	while ((temp != NULL) && (root == temp->right)) {
		root = temp;
		temp = temp->parent;
	}
	return printf("Successor of %d is %d\n", root->key, temp->key);
}

int predecessor(Node* root) {
	Node* temp = new_node(NULL);
	if (root->left != NULL) {
		temp = treemax(root->left);
		return printf("Predecessor of %d is %d \n", root->key, temp->key);
	}
	temp = root->parent;
	while ((temp != NULL) && (root == temp->left)) {
		root = temp;
		temp = temp->parent;
	}
	return printf("Predecessor of %d is %d\n", root->key, temp->key);
}