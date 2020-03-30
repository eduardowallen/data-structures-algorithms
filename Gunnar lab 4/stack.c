//Filename:			stack.c
//Author:			Gunnar Sutter [gunnar.sutter@gmail.com]
//Date:				2020-02-09
//
//Description:		File containing the functions used to implement the stack
//					and the functionality required
#include "stack.h";

//Function that initalizes the stack
//
//Arguments:		init_stack	-	double pointer to the Stack struct that we want
//								to initialize
//Returnvalue:	bool			-	if the momeory allocation is successful on both
//								Stack struct and the LinkedList struct it 
//								holds returns true, else false.
//Description:					Allocates memory to the Stack object and uses the 
//								initLinkedList function declared in linkedList.h to 
//								initialize the linked list used for the stack
Stack* init_stack() {
	Stack* init_stack = malloc(sizeof(Stack));
	if (init_stack) {
		init_stack->stack_list = initLinkedList(NULL, 0);
		return init_stack;
	}
	else {
		printf("Unable to allocate memory for stack!\n");
		return NULL;
	}
}

//Function that checks if a stack is empty or not
//
//Arguments:		test_stack	-	A poointer to the Stack object that we want to test
//Returnvalue:	bool			-	Returns true if the Stack is empty and false if not
//
//Description:		Checks if the linked list sentinel nextpointer is pointing at the 
//					sentinel. If it does, that shows that no other nodes are present 
//					in the linked list
bool stack_empty(Stack* test_stack) {
	return test_stack->stack_list->sentinel->next == test_stack->stack_list->sentinel;
}

//Function that adds a value to the queue
//
//Arguments:		push_stack		-	a double pointer to the Stack struct 
//									that we want to add a value to.
//				value			-	an integer value that we want to add
//Returnvalue:	bool				-	If memory for a node is successfully 
//									allocated true is returned, else false
//Description:	Allocates memory to a new node that will hold the value
//				we want to add to the stack and then adds the node to the
//				linked list. Error handling for insert is not yet implemented
//				but this function still handles the returnvalue in case of
//				future updates.
bool stack_push(Stack* push_stack, int value) {
	if (push_stack == NULL) {
		printf("Stack is NULL when trying to push value! \n");
		return false;
	}
	ll_Node* push_node = malloc(sizeof(ll_Node));
	if (push_node) {
		push_node->key = value;
		if (insert(push_stack->stack_list, push_node))
			return true;
		else
			return false;
	}
	else {
		printf("Unable to allocate memory for new stack node!\n");
		return false;
	}
}

//Function that removes a value from the Stack and returns it
//
//Arguments:		pop_stack		-	A pointer to the Stack struct that we
//									want to pop
//Returnvalue:	int				-	the "latest" value in the queue is returned
//									since Stack uses LIFO value access
//Description:	Uses the linked list delete function to get the "latest" node
//				and stores its key in a local varieble before its memory is 
//				deallocated. Finally returns the value in the deleted node.
int stack_pop(Stack* pop_stack) {
	ll_Node* return_node = delete(pop_stack->stack_list, pop_stack->stack_list->sentinel->next);
	int return_val = return_node->key;
	free(return_node);
	return return_val;
}

//Function takes an array of integers and fills the Stack
//
//Arguments:		stack		-	A double pointer to the Stack struct that we want 
//								filled.
//				fill_arr		-	the array if integers that holds the values we
//								want to add to the queue.
//				arr_size		-	An integer that that holds the size of the fill_arr
//Returnvalue:	bool			-	if the enqueue function fails for any of the values,
//								false is returned, else true is returned.
//Description:	loops through the array and adds its values to the Stack.
bool fill_stack(Stack* stack, int* fill_arr, int arr_size) {
	for (int a = 0; a < arr_size; a++) {
		if (!stack_push(stack, fill_arr[a]))
			return false;
	}
	return true;
}