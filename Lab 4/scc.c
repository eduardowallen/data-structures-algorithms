/* Created by Eduardo Wallén & Junior Corazza */
#include "scc.h"

Stack_s* CreateStack(int cap) {
	Stack_s* temp = (Stack_s*)malloc(sizeof(Stack_s));
	if (temp == NULL)
		return NULL;
	temp->cap = cap;
	temp->array = (int*)malloc(sizeof(int) * cap);
	temp->count = -1;
	return temp;
}

Graph_s* CreateGraph_scc(int V) {
	Graph_s* graph = (Graph_s*)malloc(sizeof(Graph_s));
	if (graph == NULL) // Check if memory was allocated
		return NULL;
	graph->V = V;
	graph->array = (Node_s*)malloc(V * sizeof(Node_s));
	if (graph->array != NULL) {
		for (int i = 0; i < V; ++i)
			graph->array[i] = NULL;
		return graph;
	}
	else return NULL;
}

Node_s* CreateNode_scc(int key) {
	Node_s* newNode = (Node_s*)malloc(sizeof(Node_s));
	if (newNode != NULL) {
		newNode->V = key;
		newNode->next = NULL;
		return newNode;
	}
	printf("The memory could not be allocated.\n");
	return NULL;
}

void addEdge(Graph_s* graph, int v1, int v2) {
	Node_s* newNode = CreateNode_scc(v2);
		newNode->V = v2;
  		newNode->next = graph->array[v1];
		graph->array[v1] = newNode;
} 

void push(Stack_s* stack, int key) {
	if (stack->count == stack->cap) {
		printf("Stack overflow.\n");
		exit(0);
	}
	stack->count++;
	stack->array[stack->count] = key;
}

int pop(Stack_s* stack) {
	int temp = stack->array[stack->count];
	stack->count--;
	return temp;
}

int IsEmpty(Stack_s* stack) {
	return(stack->count == -1);
}

void DFS(Stack_s* stack, Graph_s* graph, int v, int visited[]) {
	visited[v] = 1;
	Node_s* temp = graph->array[v];
	while (temp) {
		if (visited[temp->V] == 0)
			DFS(stack, graph, temp->V, visited);
		temp = temp->next;
	}
	push(stack, v);
}


//Create a new adjacency list and copy the older one in reverse order
Graph_s* GetReverse(Graph_s* graph) {
	int i;
	graph->array2 = (Node_s*)malloc(sizeof(Node_s) *graph->V);
	if (graph->array2 != NULL) {
		for (int i = 0; i < graph->V; ++i)
			graph->array2[i] = NULL;
	}
	Node_s* temp;
	for (i = 0; i < graph->V; i++) {
		temp = graph->array[i]; 
		while (temp) {
			Node_s* node = CreateNode_scc(i);
			if (graph->array2 != NULL) {
				node->next = graph->array2[temp->V];
				graph->array2[temp->V] = node;
				temp = temp->next;
			}
		}
	}
	free(graph->array);
	return graph;
}

void DFSutil(Graph_s* graph, int v, int visited[]) {
	// Mark the current node as visited and print it 
	visited[v] = 1;
	printf("%d | ", v);

	Node_s* temp = graph->array2[v];
	while (temp) {
		if (visited[temp->V] == 0)
			DFSutil(graph, temp->V, visited);
		temp = temp->next;
	}
}

// The main function that finds and prints all strongly connected components
void print_scc(Graph_s* graph) {
	Stack_s* stack = CreateStack(graph->V);

	int i, visited[99];
	for (i = 0; i < graph->V; i++)
		visited[i] = 0;
	for (i = 0; i < graph->V; i++)
		if (visited[i] == 0)
			DFS(stack, graph, i, visited);
	Graph_s* gr = GetReverse(graph);
	for (i = 0; i < graph->V; i++)
		visited[i] = 0;
	printf("Strongly connected components in graph:\n");
	while (!IsEmpty(stack)) {
		int v = pop(stack);
		if (visited[v] == 0) {
			DFSutil(graph, v, visited);
			printf("\n");
		}
	}
} 