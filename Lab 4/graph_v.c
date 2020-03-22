#include "graph_v.h"

Graph* CreateGraph(int V) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	if (graph == NULL) // Check if memory was allocated
		return NULL;
	graph->V = V;
	graph->array = (AdjList*)malloc(V * sizeof(AdjList));	// Size of array is V, allocate memory for the array
	if (graph->array != NULL) {
		for (int i = 0; i < V; ++i)
			graph->array[i].head = NULL;
		return graph;
	}
	else return NULL;
}
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
int getNumVertices(Graph* graph){
	return graph->V;
}
int getNumEdges(Graph* graph) {
	int sum = 0;
	for (int i = 0; i < graph->V; i++) {
		Node* temp = graph->array[i].head;
		while (temp) {
			temp = temp->next;
			sum++;
		}
	}
	return sum;
}
int getNeighbours(Graph* graph, int v1) {
	Node* temp = graph->array[v1].head;
	printf("Vertices connected to %d: ", v1);
	while (temp) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int getInNeighbours(Graph* graph, int v1) {
}
int getOutNeighbours(Graph* graph, int v1) {
}
void addDirectedEdge(Graph* graph, int v1, int v2) {
	Node* newNode = createNode(v2);			// Create a new node for v2
	newNode->next = graph->array[v1].head;	// Points v2->next to v1 
	graph->array[v1].head = newNode;		// Sets v2 to be the first in the AdjList of the vertice
} // Adding a directed edge from v1 ---> v2
void addUndirectedEdge(Graph* graph, int v1, int v2) { // graph->array[0].head | Add an undirected edge between v1 and v2
	Node* newNode = createNode(v2);			// Creates a new node for v2
	newNode->next = graph->array[v1].head;	// Points v2->next to v1
	graph->array[v1].head = newNode;		// Sets v2 to be the first in the AdjList of the vertice
	// Adding an edge from v2 to v1 as the graph is undirected.
	newNode = createNode(v1);				// Creates a new node for v1
	newNode->next = graph->array[v2].head;	// Points v1->next to v2
	graph->array[v2].head = newNode;		// Sets v1 to be the first in the AdjList of the vertice
}
int hasEdge(Graph* graph, int v1, int v2) {
	int i;
	if (v1 == v2)
		return 1;
	Node* temp = graph->array[v1].head;
	for (i = 0; i < graph->V; i++) {
		if (temp->data == v2) {
			return 1;
			break;
		}
		else temp = temp->next;
	}
	return 0;
}
void printGraph(Graph* graph) // Print the adjacency list representation of graph
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		Node* temp = graph->array[v].head;
		printf("Adjacency list of vertex %d\n", v);
		while (temp)
		{
			printf("| %d ", temp->data);
			temp = temp->next;
		}
		printf("|\n");
	}
}
