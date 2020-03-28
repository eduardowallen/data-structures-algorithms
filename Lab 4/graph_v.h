/* Created by Eduardo Wallén & Junior Corazza */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct edge_t {
	int data;				// Integer that we store the edge data into
	struct edge_t* next;	// Pointer to the next edge
} Edge;

typedef struct adjlist_t {
	Edge* head;				// Pointer to the nodes inside the list
} AdjList;

typedef struct graph_t {
	int V;					// Amount of vertices in the graph
	AdjList* array;
} Graph;

Graph* CreateGraph(int V);
Edge* createEdge(int key);
int getNumVertices(Graph* graph);
int getNumEdges(Graph* graph);
void getNeighbours(Graph* graph, int v1);
void getInNeighbours(Graph* graph, int v1);
void getOutNeighbours(Graph* graph, int v1);
void addDirectedEdge(Graph* graph, int v1, int v2);
void addUndirectedEdge(Graph* graph, int v1, int v2);
int hasEdge(Graph* graph, int v1, int v2);
void printGraph(Graph* graph);