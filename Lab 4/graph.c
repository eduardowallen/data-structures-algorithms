#include "graph.h"
#define MAX_ARRAY_SIZE 10

// V is the amount of vertices we want the graph to hold.
Graph* createGraph(int V) {
	Graph* graph = malloc(sizeof(Graph));
	if (graph == NULL) {
		printf("ERROR: The memory for the Graph could not be allocated.\n");
		return NULL;
	}
	graph->size = V;
	graph->vertices = malloc(sizeof(Vertice) * V);
	if (graph->vertices == NULL) {
		printf("ERROR: The memory for the Graphs vertices could not be allocated.\n");
		return NULL;
	}
	graph->successor_dist_arr = malloc(sizeof(float) * graph->size);
	if (graph->successor_dist_arr == NULL) {
		printf("ERROR: The memory for the Graphs shortest distance array could not be allocated.\n");
		return NULL;
	}
	graph->predecessor_arr = malloc(sizeof(int) * graph->size);
	if (graph->predecessor_arr == NULL) {
		printf("ERROR: The memory for the Graphs predecessor array could not be allocated.\n");
		return NULL;
	}
	graph->stack = createStack();
	for (int i = 0; i < V; i++) {
		graph->vertices[i].edgeList = createList(NULL, 0);
		graph->vertices[i].key = i;
	}
	return graph;
}
int getNumVertices(Graph* graph){
	if (graph != NULL)
		return graph->size;
	else
		return 0;
}
int getNumEdges(Graph* graph) {
	int num_edges = 0;
	if (graph != NULL) {
		List* templist = NULL;
		printf("Size: %d\n", graph->size);
		for (int i = 0; i < graph->size; i++) {
			templist = graph->vertices[i].edgeList;
			num_edges += getListSize(templist);
		}
	}
	return num_edges;
}
List* getNeighbours(Graph* graph, Vertice* V) {
	List* return_list = createList(NULL, 0);
	List* in_list = getInNeighbours(graph, V);
	List* out_list = getOutNeighbours(graph, V);
	LNode* current_vertice = in_list->sentinel->next;
	LNode* tmp_vertice = NULL;
	while (current_vertice != in_list->sentinel->next) {
		tmp_vertice = createNode(current_vertice->key);
		insertNode(return_list, tmp_vertice);
		current_vertice = current_vertice->next;
	}
	current_vertice = out_list->sentinel->next;
	while (current_vertice != out_list->sentinel)
		if (!searchList(return_list, current_vertice->key)) {
			tmp_vertice = createNode(current_vertice->key);
			insertNode(return_list, tmp_vertice);
			current_vertice = current_vertice->next;
		}
	return return_list;
}
List* getInNeighbours(Graph* graph, Vertice* V) {
	List* return_list = createList(NULL, 0);
	LNode* tmp_node = NULL;
	for (int i = 0; i < graph->size; i++)
		if (searchList(graph->vertices[i].edgeList, V->key)) {
			tmp_node = createNode(i);
			insertNode(return_list, tmp_node);
		}
	return return_list;
}
List* getOutNeighbours(Graph* graph, Vertice* V) {
	List* return_list = createList(NULL, 0);
	LNode* tmp_node = NULL;
	for (int i = 0; i < graph->size; i++)
		if (searchList(graph->vertices[i].edgeList, V->key)) {
			tmp_node = createNode(i);
			insertNode(return_list, tmp_node);
		}
	return return_list;
}
// Adding a directed edge from v1 ---> v2
void addDirectedEdge(Vertice* v1, Vertice* v2) {
	float weight = 1; //different weights not implemented.
	if (!searchList(v1->edgeList, v2->key)) { // To avoid duplicate edges
		LNode* newEdge = malloc(sizeof(LNode));
		if (newEdge != NULL) {
			newEdge->key = v2->key;
			newEdge->weight = weight;
			insertNode(v1->edgeList, newEdge);
		}
	}
}
void addUndirectedEdge(Vertice* v1, Vertice* v2) {
	float weight = 1; //different weights not implemented
	addDirectedEdge(v1, v2);
	// Add another directed edge, but from v2 -> v1 (almost identical to addDirectedEdge, but checks if edgeList in v2 has the key in itself already).
	if (!searchList(v2->edgeList, v2->key)) {
		LNode* newEdge = malloc(sizeof(LNode));
		if (newEdge != NULL) {
			newEdge->key = v1->key;
			newEdge->weight = weight;
			insertNode(v2->edgeList, newEdge);
		}
	}
}