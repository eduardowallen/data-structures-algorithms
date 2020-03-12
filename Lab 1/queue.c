/* Created by Eduardo Wallén & Junior Corazza */

#include "header.h"
#define MAX_ARRAY_SIZE 15


int queue[MAX_ARRAY_SIZE];  //Global variable
int front = 0; // Global variable and sets it to 0 as queue is not initialized yet
int size = 0; // Global variable and sets it to 0 as queue is not initialized yet
int rear = 0; // Global variable and sets it to 0 as queue is not initialized yet

void enqueue(int x) {
	if (size < MAX_ARRAY_SIZE)
	{
		if (size == 0 || rear == MAX_ARRAY_SIZE-1)
		{
			queue[0] = x;
			rear = 0;
			size++;
			printf("Size: %d Rear %d. ", size, rear);
			printf("%d added to queue.\n", x);
		}
		else 
		{
			rear++;	// Adds +1 to rear 
			queue[rear] = x;	// Takes the input of x and puts it in the queue from behind
			size++; // Adds +1 to size
			printf("Size %d rear: %d. ", size, rear);
			printf("%d added to queue.\n", x); // Prints x to make sure it's the correct number added
			rear = rear % 15;
		}
	}
	else	// If rear is MAX_ARRAY_SIZE - 1, then the queue is full
		printf("Queue full.\n");	// Prints it's full
}

void dequeue() {
	if (size <= 0)	// If size is less or equal to 0 queue is empty
		printf("Queue is empty.\n");	// Prints it's empty
	else
	{
		printf("%d dequeued. Front: %d \n", queue[front], front);	// Prints the dequeued number
		size--;	// Take away 1 from size
		front++; // Adds + 1 to front
		front = front % 15;
	}
}

void display_queue() {
	int i;	// Variable i for the for-loop
	if (size <= 0)	// If size is less or equal to 0 queue is empty
		printf("Queue is empty.\n");	// Prints it's empty
	else {
		printf("Numbers in queue:\n");
		if (rear >= front) {
			for (i = front; i <= rear; i++)
				printf("%d ", queue[i]);	// Prints each number
		}
		else {
			for (i = front; i < 15; i++)
				printf("%d ", queue[i]);	// Prints each number

			for (i = 0; i <= rear; i++)
				printf("%d ", queue[i]);	// Prints each number
		}
		printf("\n");
	}
}

void Queue() {
	// inserts a personal number in the order from top to bottom (10 digits)
	enqueue(9); // start
	enqueue(4);
	enqueue(1);
	enqueue(2);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(1);
	enqueue(3);
	enqueue(1);// end

	// Displaying to check how the list looks after changes (9, 4, 1, 2, 2, 3, 4, 1, 3, 1)
	display_queue();
	// Testing the dequeue function (dequeueing 9 and 4)
	dequeue();
	dequeue();
	// Testing the enqueue function (adding 2, 4 and 5)
	enqueue(2);
	enqueue(4);
	enqueue(5);
	// Displaying to check how the list looks after changes (2, 4 and 5 should now have been added at the end of the queue)
	display_queue();
}
