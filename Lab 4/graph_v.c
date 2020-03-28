#include "graph_v.h"

Graph* CreateGraph(int V) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	if (graph == NULL) // Check if memory was allocated
		return NULL;
	graph->V = V;
	graph->array = (AdjList*)malloc(V * sizeof(AdjList));	// Size of array is V, allocate memory for the array
	if (graph->array != NULL) {
		for (int i = 1; i <= V; ++i)
			graph->array[i].head = NULL;
		return graph;
	}
	else return NULL;
}
Edge* createEdge(int key) {
	Edge* newEdge = (Edge*)malloc(sizeof(Edge));	// Allocate memory for the edge
	if (newEdge != NULL) {							// Check if memory was allocated
		newEdge->data = key;
		newEdge->next = NULL;
		return newEdge;
	}
	printf("The memory could not be allocated.\n");
	return NULL;
}
int getNumVertices(Graph* graph){
	return graph->V;
}
int getNumEdges(Graph* graph) {
	int sum = 0;
	for (int i = 1; i <= graph->V; i++) {
		Edge* temp = graph->array[i].head;
		while (temp) {
			temp = temp->next;
			sum++;
		}
	}
	return sum;
}
void getNeighbours(Graph* graph, int v1) {
	getInNeighbours(graph, v1);
	getOutNeighbours(graph, v1);
}
void getInNeighbours(Graph* graph, int v1) {
	Edge* temp;
	printf("Incoming neighbours connected to %d: ", v1);
	for (int i = 1; i <= graph->V; i++) {
		temp = graph->array[i].head;
			while (temp) {
				if (temp->data == v1)
					printf("%d | ", i);
				temp = temp->next;
			}
	}
	printf("\n");
}
void getOutNeighbours(Graph* graph, int v1) {
	Edge* temp = graph->array[v1].head;
	printf("Outgoing neighbours connected to %d: ", v1);
	while (temp) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
// Adding a directed edge from v1 ---> v2
void addDirectedEdge(Graph* graph, int v1, int v2) {	// vertice we want to origin from (v1), vertice we want to point to (v2)
		Edge* newEdge = createEdge(v2);			// Create a new edge, pointing to v2
		newEdge->next = graph->array[v1].head;	// Points v1 to v2
		graph->array[v1].head = newEdge;		// Sets v2 to be the first in the AdjList of v1
}
void addUndirectedEdge(Graph* graph, int v1, int v2) {
	addDirectedEdge(graph, v1, v2);
	addDirectedEdge(graph, v2, v1); // Adding an edge from v2 to v1 as the graph is undirected.
}
int hasEdge(Graph* graph, int v1, int v2) {
	int i;
	if (v1 == v2)
		return 1;
	Edge* temp = graph->array[v1].head;
	for (i = 1; i <= graph->V; i++) {
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
	for (v = 1; v <= graph->V; ++v)
	{
		Edge* temp = graph->array[v].head;
		printf("Adjacency list of vertex %d\n", v);
		while (temp)
		{
			printf("| %d ", temp->data);
			temp = temp->next;
		}
		printf("|\n");
	}
}
