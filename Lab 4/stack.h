#pragma once
#include "linkedList.h"

typedef struct stack {
	List* list;
} Stack;

Stack* createStack();

bool stackIsEmpty(Stack* stack);

bool pushStack(Stack* stack, int value);

int pop(Stack* pop_stack);

bool fillStack(Stack* stack, int* fill_arr, int arr_size);