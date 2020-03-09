#include "header.h"
/*
Det vi har kvar:
Delete
Height - size
Få bort nollan som skrivs ut
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
	temp = treesearch(root, 5);
	printf("treesearch for 5 is: %d\n", temp->key);
	predecessor(temp);
}