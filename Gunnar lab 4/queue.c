//Filename:			queue.c
//Author:			Gunnar Sutter [gunnar.sutter@gmail.com]
//Date:				2020-02-09
//
//Description:		File containing the functions used to implement the queue
//					and the functionality required
#include "queue.h"

//Function that initalizes the queue
//
//Arguments:		init_queue	-	double pointer to the Queue struct that we want
//								to initialize
//Returnvalue:	bool			-	if the momeory allocation is successful on both
//								Queue struct and the LinkedList struct it 
//								holds
//Description:					Allocates memory to the Queue object and the uses the 
//								initLinkedList function declared in linkedList.h to 
//								initialize the linked list used for the queue
Queue* init_queue() {
	Queue* return_queue = malloc(sizeof(Queue));
	if (return_queue != NULL) {
		return_queue->queue_list = initLinkedList(NULL, 0);
	}
	else {
		return NULL;
	}
	return return_queue;
}

//Function that checks if a queue is empty or not
//
//Arguments:		test_queue	-	a poointer to the Queue object that we want to test
//Returnvalue:	bool			-	returns true if the Queue is empty and false if not
//
//Description:		Checks if the linked list sentinel nextpointer is pointing at the 
//					sentinel. If it does, that shows that no other nodes are present 
//					in the linked list
bool queue_empty(Queue* test_queue) {
	return test_queue->queue_list->sentinel->next == test_queue->queue_list->sentinel;
}

//Function that adds a value to the queue
//
//Arguments:		enqueue_queue	-	a double pointer to the Queue struct 
//									that we want to add a value to.
//				value			-	an integer value that we want to add
//Returnvalue:	bool				-	If memory for a node is successfully 
//									allocated true is returned, else false
//Description:	Allocates memory to a new node that will hold the value of
//				we want to add to the queue and then adds the node to the
//				linked list. Error handling for insert is not yet implemented
//				but this function still handles the returnvalue in case of
//				future updates.
bool enqueue(Queue* enqueue_queue, int value) {
	ll_Node* enqueue_node = malloc(sizeof(ll_Node));
	if (enqueue_node) {
		enqueue_node->key = value;
		if (insert(enqueue_queue->queue_list, enqueue_node))
			return true;
		else {
			return true;
		}
	}
	else {
		printf("Unable to allocate memory for new queue node!\n");
		return false;
	}
}

//Function that removes a value from the Queue and returns it
//
//Arguments:		dequeue_queue	-	A pointer to the Queue struct that we
//									want to dequeue
//Returnvalue:	int				-	the "oldest" value in the queue is returned
//									since Queue uses FIFO value access
//Description:	Uses the linked list delete function to get the "oldest" node
//				and stores its key in a local varieble before its memory is 
//				deallocated. Finally returns the value in the deleted node.
int dequeue(Queue* dequeue_queue) {
	ll_Node* return_node = delete(dequeue_queue->queue_list, dequeue_queue->queue_list->sentinel->prev);
	int return_key = return_node->key;
	free(return_node);
	return return_key;
}