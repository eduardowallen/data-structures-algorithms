#include "tree.h"

BTree* createTree() {
	BTree* new_tree = malloc(sizeof(BTree));
	new_tree->root = NULL;
}

BTNode* createNode(int node_key) {
	BTNode* new_node = malloc(sizeof(BTNode));
	new_node->key = node_key;
	new_node->num = 0;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

BTNode* treeMinimum(BTNode* start_node) {
	BTNode* current_node = start_node;
	while (current_node->left) {
		current_node = current_node->left;
	}
	return current_node;
}

BTNode* treeMaximum(BTNode* start_node) {
	BTNode* current_node = start_node;
	while (current_node->right) {
		current_node = current_node->right;
	}
	return current_node;
}

BTNode* treeSearch(BTNode* start_node, int search_key) {
	BTNode* current_node = start_node;
	if (current_node->key == search_key || current_node == NULL) {
		return current_node;
	}
	if (current_node->key > search_key)
		return treeSearch(current_node->left, search_key);
	return treeSearch(current_node->right, search_key);
}

BTNode* inOrderTreeWalk(BTNode* start_node, int depth) {
	if (start_node) {
		BTNode* current_node = start_node;
		if (current_node) {
			inOrderTreeWalk(current_node->left, depth + 1);
		}
		printf("%.2d - d:%d\n", current_node->key, depth);
		inOrderTreeWalk(current_node->right, depth + 1);
	}
}

//Error?
BTNode* treeSuccessor(BTNode* search_node) {
	if (search_node->right) {
		return treeMinimum(search_node->right);
	}
	BTNode* current_node = search_node->parent;
	while (current_node && search_node == current_node->right) {
		search_node = current_node;
		current_node = search_node->parent;
	}
	return current_node;
}

BTNode* treePredecessor(BTNode* search_node) {
	if (search_node->left) {
		return treeMaximum(search_node->left);
	}
	BTNode* current_node = search_node->parent;
	while (current_node && search_node == current_node->left) {
		search_node = current_node;
		current_node = search_node->parent;
	}
	return current_node;
}

void treeInsert(BTree* _tree, BTNode* insert_node) {
	printf("%d, ", insert_node->key);
	BTNode* tmp_node = NULL;
	BTNode* current_node = _tree->root;
	while (current_node) {
		tmp_node = current_node;
		if (current_node->key > insert_node->key) {
			current_node = current_node->left;
		}
		else {
			current_node = current_node->right;
		}
	}
	insert_node->parent = tmp_node;
	if (tmp_node == NULL) {
		_tree->root = insert_node;
	}
	else {
		if (tmp_node->key == insert_node->key) {
			tmp_node->num++;
		}
		else if (insert_node->key < tmp_node->key) {
			tmp_node->left = insert_node;
		}
		else {
			tmp_node->right = insert_node;
		}
	}
}

BTNode* treeDelete(BTree* _tree, BTNode* delete_node) {
	BTNode* return_node = NULL;
	BTNode* tmp_node = NULL;
	if (delete_node->left == NULL || delete_node->right) {
		return_node = delete_node;
	}
	else {
		return_node = treeSuccessor(delete_node);
	}
	if (return_node->left) {
		tmp_node = return_node->left;
	}
	else {
		tmp_node = return_node->right;
	}
	if (tmp_node) {
		tmp_node->parent = return_node->parent;
	}
	if (return_node->parent == NULL) {
		_tree->root = tmp_node;
	}
	else {
		if (return_node = return_node->parent->left) {
			return_node->parent->left = tmp_node;
		}
		else {
			return_node->parent->right = tmp_node;
		}
	}
	if (return_node == delete_node) {
		delete_node->key = return_node->key;
	}
	return return_node;
}

int getMaxDepth(BTNode* start_node)
{
	if (start_node == NULL)
		return 0;
	else
	{
		int depth_left = getMaxDepth(start_node->left);
		int depth_right = getMaxDepth(start_node->right);
		return (depth_left > depth_right ? (depth_left + 1) : (depth_right + 1));
	}
}

int rotateLeft(BTree* _tree, BTNode* rotation_node) {
	BTNode* tmp_node = rotation_node->right;
	rotation_node->right = tmp_node->left;
	if (tmp_node != _tree->root) {
		tmp_node->left->parent = rotation_node;
	}
	tmp_node->parent = rotation_node->parent;
	if (rotation_node->parent == _tree->root) {
		_tree->root = tmp_node;
	}
	else if (rotation_node == rotation_node->parent->left) {
		rotation_node->parent->left = tmp_node;
	}
	else {
		rotation_node->parent->right = tmp_node;
	}
	tmp_node->left = rotation_node;
	rotation_node->parent = tmp_node;
	return 1;
}

int rotateRight(BTree* _tree, BTNode* rotation_node) {
	BTNode* tmp_node = rotation_node->left;
	rotation_node->left = tmp_node->right;
	if (tmp_node != _tree->root) {
		tmp_node->right->parent = rotation_node;
	}
	tmp_node->parent = rotation_node->parent;
	if (rotation_node->parent == _tree->root) {
		_tree->root = tmp_node;
	}
	else if (rotation_node == rotation_node->parent->right) {
		rotation_node->parent->right = tmp_node;
	}
	else {
		rotation_node->parent->left = tmp_node;
	}
	tmp_node->right = rotation_node;
	rotation_node->parent = tmp_node;
	return 1;
}

int balanceBTree(BTree* _tree, BTNode* start_node) {
	BTNode* current_node = start_node;
	if (current_node == NULL) {
		return NULL;
	}
	int right_depth = getMaxDepth(current_node->right);
	int left_depth = getMaxDepth(current_node->left);

	printf("sn: %d; ld: %d, rd: %d\n", start_node->key, left_depth, right_depth);

	if (left_depth > right_depth + 1) {
		if (current_node->left) {
			rotateRight(_tree, current_node->left);
		}
		else {
			//return NULL;
		}
	}
	else if (right_depth > left_depth + 1) {
		if (current_node->right) {
			rotateLeft(_tree, current_node->right);
		}
		else {
			//return NULL;
		}
	}
	return balanceBTree(_tree, start_node->parent);
}

void printDepthTree(BTNode* root)
{
	int depth = getMaxDepth(root);

	for (int current_depth = 1; current_depth <= depth; current_depth++)
	{
		printDepth(root, current_depth);
		printf("\n");
	}
}

/* Print nodes at a given level */
void printDepth(BTNode* root, int depth)
{
	if (root == NULL)
		return;
	if (depth == 1)
		printf("%d ", root->key);
	else if (depth > 1)
	{
		printDepth(root->left, depth - 1);
		printDepth(root->right, depth - 1);
	}
}

int printTreeInOrder(BTNode* node) {
	if (node == NULL) {
		return NULL;
	}
	printTreeInOrder(node->left);

	printf("%d ", node->key);

	printTreeInOrder(node->right);
}

int treeIsEmpty(BTree* tree) {
	if (tree->root->left == NULL && tree->root->right == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}