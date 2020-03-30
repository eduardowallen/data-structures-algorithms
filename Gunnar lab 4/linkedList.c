//Filename:			my_linkedList.c
//Author:			Gunnar Sutter [gunnar.sutter@gmail.com]
//Date:				2020-02-03
//
//Description:		File containing the functions used to implement the linkedList object
//					and the functionality required

#include "linkedList.h"

///Function that checks if a linked list is empty or not
///If the sentinel points at itself the list is empty
///
///Arguments:		tmp_ll			-	a pointer to a linkedList object
///Returnvalue:		bool				-	true if the linked list is empty 
///										othervise true
bool isEmpty(linkedList* tmp_ll) {
	return tmp_ll->sentinel->next == tmp_ll->sentinel;
}

///Function initalising a linked list object.
///Allocates memory and primes the sentinel
///
///Argumants:		init_list		-	a doublepointer to a NULL value of type linkedList
///Returnvalue:		bool				-	false if memory allocation fails, othervise true
//Description:	This function handles the initialization of the linkedList object. Since I
//				want to handle the memory allocation inside the init function I send an empty
//				duible pointer to the object I want to initalize.
linkedList* initLinkedList(int* input_arr, int arr_size) {
	linkedList* init_list = malloc(sizeof(linkedList));
	if (init_list) {
		init_list->sentinel = malloc(sizeof(ll_Node));
		if (init_list->sentinel) {
			init_list->sentinel->key = 1234567;
			init_list->sentinel->next = init_list->sentinel;
			init_list->sentinel->prev = init_list->sentinel;
		}
		else {
			printf("Unable to allocate memory for linked list.\n");
			return NULL;
		}
	}
	else if (input_arr && arr_size > 0) {
		ll_Node* tmp_Node = NULL;
		for (int a = 0; a < arr_size; a++) {
			tmp_Node = malloc(sizeof(ll_Node));
			if (tmp_Node) {
				tmp_Node->key = input_arr[a];
				tmp_Node->weight = 1;
				insert(init_list, tmp_Node);
			}
			else {
				return NULL;
			}
		}
	}
	return init_list;

}

///Function inserting a node at the beginning af the linked list
///Places the new node between the sentinel and the first object in the list
///If this is the first item both the prev and next links point at the sentinel
///
///Arguments:		ll				-	a boublepointer to a linkedList object
///					in				-	Node that is inserted in to the linked list.
///Returnvalue:		bool				-	No error handling implemented. Returns true
bool insert(linkedList* ll, ll_Node* in) {
	ll_Node* insert_node = in;
	linkedList* tmp_ll = ll;
	insert_node->next = tmp_ll->sentinel->next;
	tmp_ll->sentinel->next->prev = insert_node;
	tmp_ll->sentinel->next = insert_node;
	insert_node->prev = tmp_ll->sentinel;
	return true;
}

///Function that searches the linked list for the first matching key
///Traverses the linked list from the sentinel to the next element in the list
///until it finds a match or until it returns back to the sentinel
///
///Arguments:		ll				-	a pointer to a linked list object
///					search_key		-	integer that we try to match with the node keys
///Returnvalue:		ll_Node*			-	a pointer to a matching node object. If no match 
///										is found, NULL is returned
ll_Node* search(linkedList* ll, int search_key) {
	if (getListSize(ll) == 0)
		return NULL;
	ll_Node* tmp_node = ll->sentinel->next;
	while (tmp_node != ll->sentinel) {
		if (tmp_node->key == search_key)
			return tmp_node;
		tmp_node = tmp_node->next;
	}
	return NULL;
}

///Function that deletes a node from the linked				
///
///Arguments:		ll				-	a pointer to a linked list object
///										Is this required? see no use in this 
///										functions current implementation.
///					delete_node		-	pointer to the node that we want to 
///										delete from the list
///Returnvalue:		ll_Node*			-	pointer to the deleted node
///
ll_Node* delete(linkedList* ll, ll_Node* delete_node) {
	if (delete_node != NULL) {
		delete_node->prev->next = delete_node->next;
		delete_node->next->prev = delete_node->prev;
		return delete_node;
	}
	return NULL;
}

///Function that returns the node containing the largest value in the list
///Traverses the list from the sentinel and to the next node until it
///comes back to the sentinel and returns the higest value encountered
///
///Arguments:		ll				-	a pointer to a linked list object
///Returnvalue:		ll_Node*			-	a pointer to the node containing the
///										highest key-value
ll_Node* maximum(linkedList* ll) {
	ll_Node* tmp_node = ll->sentinel->next;
	ll_Node* max_node = tmp_node;
	while (tmp_node != ll->sentinel) {
		if (tmp_node->key > max_node->key) {
			max_node = tmp_node;
		}
		tmp_node = tmp_node->next;
	}
	return max_node;
}

///Function that returns the node containing the smallest value in the list
///Traverses the list from the sentinel and to the next node until it
///comes back to the sentinel and returns the smallest value encountered
///
///Arguments:		ll				-	a pointer to a linked list object
///Returnvalue:		ll_Node*			-	a pointer to the node containing the
///										smallest key-value
ll_Node* minimum(linkedList* ll) {
	ll_Node* tmp_node = ll->sentinel->next;
	ll_Node* min_node = tmp_node;
	while (tmp_node != ll->sentinel) {
		if (tmp_node->key < min_node->key) {
			min_node = tmp_node;
		}
		tmp_node = tmp_node->next;
	}
	return min_node;
}

///Function the returns the closest larger number in the list
///
///Arguments:		ll				-	a pointer to a linked list object
///					search_node		-	a pointer to the node we want to find
///										the successor of.
///Returnvalue:		ll_Node*			-	a pointer to the node that contains the
///										successor
ll_Node* successor(linkedList* ll, ll_Node* search_node) {
	ll_Node* suc_Node = maximum(ll);
	if (suc_Node == search_node) {
		return NULL;
	}
	ll_Node* tmp_Node = ll->sentinel->next;
	while (tmp_Node != ll->sentinel) {
		if (tmp_Node->key > search_node->key&& tmp_Node->key < suc_Node->key) {
			suc_Node = tmp_Node;
		}
		tmp_Node = tmp_Node->next;
	}
	return suc_Node;
}

///Function the returns the closest smaller number in the list
///
///Arguments:		ll				-	a pointer to a linked list object
///					search_node		-	a pointer to the node we want to find
///										the predecessor of.
///Returnvalue:		ll_Node*			-	a pointer to the node that contains the
///										predecessor
ll_Node* predecessor(linkedList* ll, ll_Node* search_node) {
	ll_Node* pre_Node = minimum(ll);
	if (pre_Node == search_node) {
		return pre_Node;
	}
	ll_Node* tmp_Node = ll->sentinel->next;
	while (tmp_Node != ll->sentinel) {
		if (tmp_Node->key < search_node->key && tmp_Node->key > pre_Node->key) {
			pre_Node = tmp_Node;
		}
		tmp_Node = tmp_Node->next;
	}
	return pre_Node;
}

///Function that frees the allocated memory of the linkedList object
///Traverses the list and deallocates the memory of the ll_Nodes
///When all the nodes are free, deallocates the memory of the linkedList object
///
///Arguments:		ll				-	a pointer to a linked list object
bool free_linkedList(linkedList* ll) {
	ll_Node* tmp_node = ll->sentinel->next;

	while (tmp_node != ll->sentinel) {
		tmp_node = tmp_node->next;
		if (tmp_node->prev)
			free(tmp_node->prev);
	}
	if (ll) {
		free(ll);
	}
	return true;
}

//	TTTTTTTT EEEEEE   SSSSSS  TTTTTTTT
//     TT    E        S          TT 
//	   TT    EEEEE    SSSSSS     TT
//     TT    E	           S     TT
//	   TT    EEEEEE   SSSSSS     TT
//
///Function initalising a linked list object.
///Allocates memory and primes the sentinel
///
///Argumants:		init_list		-	a doublepointer to a linkedList object
///Returnvalue:		bool				-	false if memory allocation fails, othervise true
bool test_initLinkedList(linkedList* init_list, int* input_arr, int arr_size) {
	//init_list = malloc(sizeof(linkedList));
	if (init_list) {
		init_list->sentinel = malloc(sizeof(ll_Node));
		if (init_list->sentinel) {
			init_list->sentinel->key = 42;
			init_list->sentinel->next = init_list->sentinel;
			init_list->sentinel->prev = init_list->sentinel;
		}
		else {
			printf("Unable to allocate memory for linked list.\n");
			return false;
		}
	}
	else return true;
	if (input_arr && arr_size > 0) {
		ll_Node* tmp_Node = NULL;
		for (int a = 0; a < arr_size; a++) {
			tmp_Node = malloc(sizeof(ll_Node));
			if (tmp_Node) {
				tmp_Node->key = input_arr[a];
				insert(init_list, tmp_Node);
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int getListSize(linkedList* ll) {
	if (ll == NULL)
		return 0;
	int num_nodes = 0;
	ll_Node* count_node = ll->sentinel;
	while (count_node->next != ll->sentinel) {
		num_nodes++;
		count_node = count_node->next;
	}
	return num_nodes;
}

ll_Node* createLLNode(int insert_key) {
	ll_Node* return_node = malloc(sizeof(ll_Node));
	if (return_node == NULL) {
		return NULL;
	}
	return_node->key = insert_key;
	return return_node;
}

void printList(linkedList* list) {
	ll_Node* current_node = list->sentinel->next;
	while (current_node != list->sentinel) {
		printf("%d", current_node->key);
		current_node = current_node->next;
		if (current_node != list->sentinel)
			printf(", ");
	}
}