/* Created by Eduardo Wallén & Junior Corazza */
#include "queue.h"

Queue* Queue_Initialize() {
    Queue* queue_r = malloc(sizeof(Queue));
    if (queue_r != NULL) {
        queue_r->list = createList(NULL, 0);
    }
    else {
        return NULL;
    }
    return queue_r;
}

bool QueueEmpty(Queue* temp) {
    return temp->list->sentinel->next == temp->list->sentinel;
}

bool Enqueue(Queue* enqueue_queue, int value) {
    LNode* enqueue = malloc(sizeof(LNode));
    if (enqueue) {
        enqueue->key = value;
        if (insertNode(enqueue_queue->list, enqueue))
            return true;
        else {
            return true;
        }
    }
    else {
        printf("Memory allocation failed.\n");
        return false;
    }
}

int Dequeue(Queue* dequeue_queue) {
    LNode* node_r = deleteNode(dequeue_queue->list, dequeue_queue->list->sentinel->prev);
    int key = node_r->key;
    free(node_r);
    return key;
}