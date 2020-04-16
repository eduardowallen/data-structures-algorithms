/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
	int V;
	struct node_s* next;
}Node_s;

typedef struct graph_s {
	int V;
	Node_s** array;
	Node_s** array2;
}Graph_s;

typedef struct stack_s {
	int data;
	int cap;
	int* array;
	int count;
}Stack_s;

Stack_s* CreateStack(int cap);
Graph_s* CreateGraph_scc(int V);
Node_s* CreateNode_scc(int key);
void addEdge(Graph_s* graph, int v1, int v2);
void push(Stack_s* stack, int key);
int pop(Stack_s* stack);
int IsEmpty(Stack_s* stack);
void DFS(Stack_s* stack, Graph_s* graph, int v, int visited[]);
Graph_s* GetReverse(Graph_s* graph);
void DFSutil(Graph_s* graph, int v, int visited[]);
void print_scc(Graph_s* graph);