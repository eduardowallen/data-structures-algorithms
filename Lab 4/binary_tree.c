/* Created by Eduardo Wallén & Junior Corazza */
#include "binary_tree.h"

BSTNode* new_node(int x) {
	BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
	if (temp == NULL) {
		printf("Could not allocate memory for the node.");
		return NULL;
	}
	temp->key = x;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}
BSTNode* insert(BSTNode* T, BSTNode* z) {
	BSTNode* y, * x;
	y = NULL;
	x = T;
	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else x = x->right;
	}
	z->parent = y;
	if (y == NULL) {
		T = z; // tree T was empty
	}	
	else if (z->key < y->key)
		y->left = z;
	else y->right = z;
	return z;
}
/* The following code (with a few additions) follows the pseudocode that can be read on page 296 in the book "Introduction to Algorithms Third edition" (ISBN: 978-0-262-03384-8)*/
void transplant(BSTNode* T, BSTNode* u, BSTNode* v) {
	BSTNode* parent_n;
	if (u->parent != NULL)
		parent_n = u->parent;
	if (u->parent == NULL)
		T = v;
	else if (u == parent_n->left)
		parent_n->left = v;
	else parent_n->right = v;
	if (v != NULL)
		v->parent = u->parent;
}
void tree_delete(BSTNode* T, BSTNode* z) {
	while (z->right != NULL)
		tree_delete(T, z->right);
	while (z->left != NULL)
		tree_delete(T, z->left);
	printf("Deleting key: %d\n", z->key);
	delete(T, z);
	if (z == T) {
		printf("Freeing the tree from the memory\n");
		free(T);
		printf("Tree has been emptied completely.\n");
	}
}
/* The following code (with a few additions) follows the pseudocode that can be read on page 298 in the book "Introduction to Algorithms Third edition" (ISBN: 978-0-262-03384-8)*/
void delete(BSTNode* T, BSTNode* z) {
	BSTNode* y, * temp;
	if (z->left == NULL)
		transplant(T, z, z->right);
	else if (z->right == NULL)
		transplant(T, z, z->left);
	else {
		y = treemin(z->right);
		if (y->parent != z) {
			transplant(T, y, y->right);
			y->right = z->right;
			temp = y->right;
			temp->parent = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		temp = y->left;
		temp->parent = y;
	}
}
void inordertreewalk(BSTNode* T) {		// print out tree in the correct order
	if (T != NULL) {
		inordertreewalk(T->left);			// Goes through left side
		printf("%d ", T->key);
		inordertreewalk(T->right);			// Goes through right side
	}
}
BSTNode* treemax(BSTNode* x) {

	while (x->right != NULL)
		x = x->right;
	return x;
}
BSTNode* treemin(BSTNode* x) {
	while (x->left != NULL)
		x = x->left;
	return x;
}
BSTNode* treesearch(BSTNode* T, int key) {
	if ((T == NULL) || (T->key == key))
		return T;
	if (T->key > key)
		return treesearch(T->left, key);
	return treesearch(T->right, key);

}
BSTNode* successor(BSTNode* z) {
	BSTNode* temp;
	if (z->right != NULL) {
		return treemin(z->right);
	}
	temp = z->parent;
	while ((temp != NULL) && (z == temp->right)) {
		temp = temp->parent;
	}
	return temp;
}
BSTNode* predecessor(BSTNode* z) {
	BSTNode* temp;
	if (z->left != NULL) {
		return treemax(z->left);
	}
	temp = z->parent;
	while ((temp != NULL) && (z == temp->left)) {
		z = temp;
		temp = temp->parent;
	}
	return temp;
}
int treeheight(BSTNode* T) {
	if (T == NULL)
		return 0;
	else
	{
		int rd = treeheight(T->right);
		int ld = treeheight(T->left);
		if (ld > rd)
			return (ld + 1);
		else return (rd + 1);
	}
}
int treesize(BSTNode* T) {
	if (T == NULL)
		return 0;
	else
		return(1 + treesize(T->right) + treesize(T->left));
}
// ********** PRINT TREE START *********** 
void padding(char ch, int n) {
	int i;

	for (i = 0; i < n; i++)
		putchar(ch);
}
void printTree(BSTNode* T, int level) {
	if (T == NULL) {
		padding('\t', level);
		puts("~");
	}
	else {
		printTree(T->right, level + 1);
		padding('\t', level);
		printf("%d\n", T->key);
		printTree(T->left, level + 1);
	}
}
// ********* PRINT TREE END *************/

/* Function that grows a tree for us */
void growTree(BSTNode* T) {
	insert(T, new_node(5));		// Inserts node
	insert(T, new_node(3));		// Inserts node
	insert(T, new_node(4));		// Inserts node
	insert(T, new_node(50));	// Inserts node
	insert(T, new_node(49));	// Inserts node
	insert(T, new_node(12));	// Inserts node
	insert(T, new_node(11));	// Inserts node
	insert(T, new_node(42));	// Inserts node
}