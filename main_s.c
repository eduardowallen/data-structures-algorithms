#include "header_s.h"

int stack() {
	display();	// Execute display function to see numbers in stack 
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
	display();	// Displays numbers in stack (9, 4, 1, 2, 2, 3, 4, 1, 3, 1)
	pop();		// Pops the last inserted number (1)
	push(2);	// Inserts a number (2) into the stack
	display();	// Displays numbers in stack (9, 4, 1, 2, 2, 3, 4, 1, 3, 2)
}