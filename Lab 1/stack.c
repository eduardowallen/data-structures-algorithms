/* Created by Eduardo Wallén & Junior Corazza */

#include "stack.h"

#define MAX_ARRAY_SIZE 15

int stack[MAX_ARRAY_SIZE], top, i; // Global variables

void push(int x){
	if (top == MAX_ARRAY_SIZE)	// If top is equal to array size, the stack is full
		printf("Stack overflow.\n");	// Prints it's full
	else {
		printf("%d pushed.\n", x);	// Prints out that x are pushed
		stack[top] = x;	// Puts the input x in the top value in the array stack
		top++;	// Adds 1 to top
	}
}

void pop() {
	if (top <= 0) // If top is equal or less than 0 the stack is empty
		printf("Stack underflow.\n");	// Prints it's empty
	else {
		printf("%d popped.\n", stack[top-1]);	// Prints out which number that popped
		top--;	// Takes away 1 from top
	}
}

void display_stack() {
	if (top <= 0)	// If top is equal or less than 0 the stack is empty
		printf("Stack underflow.\n");	// Prints it's empty
	else {
		printf("Elements in stack: ");	// Prints which numbers are in stack
		for (i = 0; i < top; i++) {	// For-loop which loops through from top to 1
			printf("%d ", stack[i]);	// Prints every i value
		}
		printf("\n");
	}
}
void Stack() {
	display_stack();	// Execute display function to see numbers in stack 
	pop();		// Execute pop function to pop the last number
	// inserts a personal number in the order from top to bottom (10 digits)
	push(9); // start
	push(4);
	push(1);
	push(2);
	push(2);
	push(3);
	push(4);
	push(1);
	push(3);
	push(1); // end
	display_stack();	// Displays numbers in stack (9, 4, 1, 2, 2, 3, 4, 1, 3, 1)
	pop();		// Pops the last inserted number (1)
	push(2);	// Inserts a number (2) into the stack
	display_stack();	// Displays numbers in stack (9, 4, 1, 2, 2, 3, 4, 1, 3, 2)
}