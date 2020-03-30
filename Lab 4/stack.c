#include "stack.h"

/* This code only includes relevant functions to meet the conditions of Lab 4 */
// Creates the stack
Stack* createStack() {
	Stack* init_stack = malloc(sizeof(Stack));
	if (init_stack == NULL) {
		printf("Memory for the stack could not be allocated.\n");
		return NULL;
	}
	init_stack->list = createList(NULL, 0);
	return init_stack;
}

// Checks if the stack is empty
bool stackIsEmpty(Stack* stack) {
	return stack->list->sentinel->next == stack->list->sentinel;
}

//Function that adds a value to the queue
bool pushStack(Stack* stack, int value) {
	if (stack == NULL) {
		printf("Stack is NULL when using stackEnqueue.\n");
		return false;
	}
	LNode* tempnode = malloc(sizeof(LNode));
	if (tempnode) {
		tempnode->key = value;
		if (insertNode(stack->list, tempnode))
			return true;
		return false;
	}
	printf("Memory for the new stack node could not be allocated.\n");
	return false;
}
int pop(Stack* stack) {
	LNode* tempnode = deleteNode(stack->list, stack->list->sentinel->next); // Remove a node from the list (LIFO) and save a pointer to it as we will use it as tempnode below
	int val = tempnode->key; // Grab the value of the tempnodes key before we free it from memory
	free(tempnode);	// Free the memory of the node
	return val;	// Return the value that was in the (now deleted) node.
}