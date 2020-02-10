#include "header.h"

int main() {
	List* list1, * list2;
	//List* list2;
	Node* tempnode;
	list1 = createList(1);
	list2 = createList(2);
	tempnode = createNode(1);
	insert(&list1, &tempnode);
	insert(&list2, &tempnode);
	tempnode = createNode(2);
	insert(&list1, &tempnode);
	insert(&list2, &tempnode);
	print(&list1);
	print(&list2);
	search(&list1, 2);
	printf("Maximum: %p", maximum(&list1));
}