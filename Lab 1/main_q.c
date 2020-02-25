#include "header_q.h"

int queue() {
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