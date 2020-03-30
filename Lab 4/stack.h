#pragma once
#include "linkedlist.h"

typedef struct stack {
	List* list;
} Stack;

Stack* createStack();
bool stackIsEmpty(Stack* stack);
bool pushStack(Stack* stack, int value);
int pop(Stack* stack);