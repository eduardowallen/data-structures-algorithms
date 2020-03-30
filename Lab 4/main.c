#include "graph.h"

int main() {
	printf("Exercise 1:\n  - Testing neighbours functions:\n");
	Graph* ex_1_graph = createGraph(5);

	addDirectedEdge(&ex_1_graph->vertices[0], &ex_1_graph->vertices[1]);
	addUndirectedEdge(&ex_1_graph->vertices[0], &ex_1_graph->vertices[3]);
	addDirectedEdge(&ex_1_graph->vertices[1], &ex_1_graph->vertices[2]);
	addDirectedEdge(&ex_1_graph->vertices[2], &ex_1_graph->vertices[4]);
	addDirectedEdge(&ex_1_graph->vertices[4], &ex_1_graph->vertices[1]);

	printf("\nIn neighbors:  ");
	printList(getInNeighbours(ex_1_graph, &ex_1_graph->vertices[1]));

	printf("\nOut neighbors: ");
	printList(getOutNeighbours(ex_1_graph, &ex_1_graph->vertices[1]));

	printf("\nAll neighbors: ");
	printList(getNeighbours(ex_1_graph, &ex_1_graph->vertices[1]));

	printf("\n------------------------------------- \n");
}