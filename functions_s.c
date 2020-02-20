#include <stdio.h>
#include "header_s.h"

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

void display() {
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