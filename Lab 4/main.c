#include "graph_v.h"

int main() {
	int V = 5;
	Graph* graph = CreateGraph(V);
	addUndirectedEdge(graph, 0, 1);
	addDirectedEdge(graph, 0, 4);
	addUndirectedEdge(graph, 1, 2);
	addUndirectedEdge(graph, 1, 3);
	addDirectedEdge(graph, 1, 4);
	addDirectedEdge(graph, 2, 3);
	addUndirectedEdge(graph, 3, 4);

	printGraph(graph);
}