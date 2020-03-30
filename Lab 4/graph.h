/* Created by Eduardo Wallén & Junior Corazza */
#pragma once
#include <math.h>
#include "linkedList.h"
#include "stack.h"
//#include "queue.h"

#define VERT_COLOR_WHITE 0
#define VERT_COLOR_GREY 1
#define VERT_COLOR_BLACK 2

typedef struct vertice_t {
	List* edgeList;				// Pointer to the nodes inside the list
	int key;
	int color;
	int visit;
	int predecessor;
	int finished;
} Vertice;

typedef struct graph_t {
	int size;					// Amount of vertices in the graph
	int time;
	float* successor_dist_arr;
	int* predecessor_arr;
	Stack* stack;
	Vertice* vertices;
} Graph;

Graph* createGraph(int num_vertices);
int getNumVertices(Graph* graph);
int getNumEdges(Graph* graph);
List* getNeighbours(Graph* graph, Vertice* V);
List* getInNeighbours(Graph* graph, Vertice* V);
List* getOutNeighbours(Graph* graph, Vertice* V);
void addDirectedEdge(Vertice* v1, Vertice* v2);
void addUndirectedEdge(Vertice* v1, Vertice* v2);