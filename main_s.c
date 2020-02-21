#include "header_s.h"

int main() {
	display();	// Execute display function to see numbers in stack 
	pop();		// Execute pop function to pop the last number
	push(9);	
	push(4);
	push(1);
	push(2);
	push(2);
	push(3);
	push(4);
	push(1);
	push(3);
	push(1);
	display();	// Execute display function to see numbers in stack
	pop();
	push(2);	// Execute pop function to pop the last number
	display();	// Execute display function to see numbers in stack
}