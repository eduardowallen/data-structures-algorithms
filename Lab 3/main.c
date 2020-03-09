#include "header.h"
/*
Det vi har kvar:
Delete
Height - size
*/
/*
			 13
		   /   \
		  5    50
		 /\    / \
		3 12  42  49
		\  /
		 4 11
*/
int main() {
	struct node* root = NULL;
	root = insert(root, new_node(13));
	insert(root, new_node(5));
	insert(root, new_node(3));
	insert(root, new_node(4));
	insert(root, new_node(50));
	insert(root, new_node(49));
	insert(root, new_node(12));
	insert(root, new_node(11));
	insert(root, new_node(42));
	inordertreewalk(root);
	treemax(root);
	treemin(root);
	Node* temp = new_node(NULL);
	temp = treesearch(root, 13);
	printf("treesearch for 13 is: %d\n", temp->key);
	predecessor(temp);
	successor(temp);
}