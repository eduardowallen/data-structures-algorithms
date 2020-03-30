//Filename:			stack.h
//Author:			Gunnar Sutter [gunnar.sutter@gmail.com]
//Date:				2020-02-03
//
//Description:		Header file for stack.c
//	

#pragma once
#include "linkedList.h"

typedef struct stack {
	linkedList* stack_list;
} Stack;

Stack* init_stack();

bool stack_empty(Stack* test_stack);

bool stack_push(Stack* push_stack, int value);

int stack_pop(Stack* pop_stack);

bool fill_stack(Stack* stack, int* fill_arr, int arr_size);