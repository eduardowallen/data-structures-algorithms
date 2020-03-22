#include "graph_v.h"

int main() {
	int V = 7;
	/*
				0
		      /   \
			 1 --> 2 <-- 6
			 ^     |
			 |	   |
			 3<----4 -- 5

	*/
	Graph* graph = CreateGraph(V);
	addUndirectedEdge(graph, 0, 1);
	addUndirectedEdge(graph, 0, 2);
	addUndirectedEdge(graph, 2, 4);
	addUndirectedEdge(graph, 4, 5);
	addDirectedEdge(graph, 1, 2);
	addDirectedEdge(graph, 4, 3);
	addDirectedEdge(graph, 3, 1);
	addDirectedEdge(graph, 6, 2);
	printf("Vertices: %d\n", getNumVertices(graph));
	printf("Edges: %d \n", getNumEdges(graph));
	getNeighbours(graph, 4);
	printGraph(graph);
	printf("%d", hasEdge(graph, 3, 1));
}