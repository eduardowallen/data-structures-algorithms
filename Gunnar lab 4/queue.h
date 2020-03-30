//Filename:			queue.h
//Author:			Gunnar Sutter [gunnar.sutter@gmail.com]
//Date:				2020-02-03
//
//Description:		Header file for queue.c
//					Function descriptions located in source file
#pragma once
#include "linkedList.h"

//Queue struct based on the LinkedList struct
//Members:			queue_list	-	pointer to a LinkedList struct
typedef struct queue {
	//Max length and so on not implemented at this time
	linkedList* queue_list;
} Queue;

Queue* init_queue();

bool queue_empty(Queue* test_queue);

bool enqueue(Queue* enqueue_queue, int value);

int dequeue(Queue* dequeue_queue);