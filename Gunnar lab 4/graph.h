#pragma once
#include <math.h>
#include "linkedList.h"
#include "queue.h"
#include "tree.h"
#include "stack.h"

#define VERT_COLOR_WHITE 0
#define VERT_COLOR_GREY 1
#define VERT_COLOR_BLACK 2

typedef struct Scc {
	int scc_num;
	linkedList* component_list;
} Scc;

typedef struct GVert {
	int key;
	int color;
	int predecessor;
	int visit;
	int finished;
	linkedList* edgeList;
} GVert;

typedef struct Graph {
	int time;
	int size;
	float* s_dist_arr;
	int* pred_arr;
	Stack* finished_stack;
	GVert* vertices;
} Graph;

Graph* createGraph(int num_vertices);

int getNumVertices(Graph* input_graph);

int getNumEdges(Graph* input_graph);

linkedList* getNeighbors(Graph* input_graph, GVert* search_vert);

linkedList* getInNeighbors(Graph* input_graph, GVert* search_vert);

linkedList* getOutNeighbors(Graph* input_graph, GVert* search_vert);

int addDirectedEdge(GVert* vert_one, GVert* vert_two);

int addUndirectedEdge(GVert* vert_one, GVert* vert_two);

int hasEdge(GVert* vert_one, GVert* vert_two);

void printGraphMatrix(Graph* print_graph);

float* graphBFS(Graph* graph, GVert* search_vert);

void graphDFS(Graph* graph);

void graphDFSVisit(Graph* graph, GVert* visit_vert);

void initSignleSource(Graph* graph, int start_vert);

void SCC(Graph* graph);

Graph* transverseGraph(Graph* graph);

bool DFS(Graph* graph, GVert* vert);

bool add_scc(Graph* graph);

bool add_scc_vert(Graph* graph, int vert);