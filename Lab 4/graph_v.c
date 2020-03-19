#include "graph_v.h"

Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// Allocate memory for the node
	if (newNode != NULL) {							// Check if memory was allocated
		newNode->data = key;
		newNode->next = NULL;
		return newNode;
	}
	printf("The memory could not be allocated.\n");
	return NULL;
}

Graph* CreateGraph(int V) {
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	if (graph == NULL) // Check if memory was allocated
		return NULL;
	graph->V = V;
	graph->array = (AdjList*)malloc(V * sizeof(AdjList));	// Size of array is V, allocate memory for the array
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;
	return graph;
}

int getNumVertices(Graph* graph){
	return graph->V;
}

/* 
Adding a directed edge from v1 ---> v2
*/
void addDirectedEdge(Graph* graph, int v1, int v2) {
	Node* newNode = createNode(v2);			// Create a new node for v2
	newNode->next = graph->array[v1].head;	// Points v2->next to v1 
	graph->array[v1].head = newNode;		// Sets v2 to be the first in the AdjList of the vertice
}
/*
graph->array[0].head
Add an undirected edge between v1 and v2
*/
void addUndirectedEdge(Graph* graph, int v1, int v2) {
	Node* newNode = createNode(v2);			// Creates a new node for v2
	newNode->next = graph->array[v1].head;	// Points v2->next to v1
	graph->array[v1].head = newNode;		// Sets v2 to be the first in the AdjList of the vertice
	// Adding an edge from v2 to v1 as the graph is undirected.
	newNode = createNode(v1);				// Creates a new node for v1
	newNode->next = graph->array[v2].head;	// Points v1->next to v2
	graph->array[v2].head = newNode;		// Sets v1 to be the first in the AdjList of the vertice
}

int hasEdge(int v1, int v2) {

}