//Filename:			linkedList.h
//Author:			Gunnar Sutter [gunnar.sutter@gmail.com]
//Date:				2020-02-03
//
//Description:		Header file for linkedList.c
//					Function descriptions located in source file
//					Also contains decalrations of structs and constants
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_node ll_Node;

//Node struct in a double linked list
//Members:			key		-	holds the actual value of the node
//					prev		-	a pointer to the previous ll_Node object
//								in the linked list.
//					next		-	a pointer to the previous ll_Node object
//								in the linked list.
struct ll_node {
	float weight;
	int key;

	ll_Node* prev;
	ll_Node* next;
};

//Linked list struct
//Members:			sentinel -	the beginning and the end of the double
//								linked list. 
typedef struct linkedList {
	ll_Node* sentinel;
} linkedList;


linkedList* initLinkedList(int* input_arr, int arr_size);

bool isEmpty(linkedList* tmp_ll);

bool insert(linkedList* tmp_ll, ll_Node* tmp_node);

ll_Node* search(linkedList* ll, int search_key);

ll_Node* delete(linkedList* ll, ll_Node* delete_node);

ll_Node* maximum(linkedList* ll);

ll_Node* minimum(linkedList* ll);

ll_Node* successor(linkedList* ll, ll_Node* search_node);

ll_Node* predecessor(linkedList* ll, ll_Node* search_node);

bool free_linkedList(linkedList* ll);

bool test_initLinkedList(linkedList* init_list, int* input_arr, int arr_size);

int getListSize(linkedList* ll);

linkedList* mergeLinkedLists(linkedList* list1, linkedList* list2);

ll_Node* createLLNode(int insert_key);

void printList(linkedList* list);