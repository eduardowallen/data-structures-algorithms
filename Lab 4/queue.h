/* Created by Eduardo Wallén & Junior Corazza */
#pragma once
#include "linkedlist.h"

typedef struct queue {
    List* list;
} Queue;

Queue* Queue_Initialize();
bool QueueEmpty(Queue* temp);
bool Enqueue(Queue* enqueue_queue, int value);
int Dequeue(Queue* dequeue_queue);