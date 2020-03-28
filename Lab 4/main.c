#include "graph_v.h"

int main() {
	int V = 7;
	/*
				1
		      /   \
			 2 --> 3 <-- 7
			 ^     |
			 |	   |
			 4<----5 -- 6


			 
	*/
	Graph* graph = CreateGraph(V);
	addUndirectedEdge(graph, 1, 2);
	addUndirectedEdge(graph, 1, 3);
	addUndirectedEdge(graph, 3, 5);
	addUndirectedEdge(graph, 5, 6);
	addDirectedEdge(graph, 2, 3);
	addDirectedEdge(graph, 5, 4);
	addDirectedEdge(graph, 4, 2);
	addDirectedEdge(graph, 7, 3);
	printf("Vertices: %d\n", getNumVertices(graph));
	printf("Edges: %d \n", getNumEdges(graph));
	printf("Get neighbours:\n");
	getNeighbours(graph, 3);
	getInNeighbours(graph, 3);
	getNeighbours(graph, 4);
	getNeighbours(graph, 5);
	printf("End\n");
	printGraph(graph);
	printf("%d", hasEdge(graph, 4, 2));

	// Exercise 2, create the map as described in the exercise

	V = 10;
	Graph* exercise2 = CreateGraph(V);
	int y, x;
	for (y = 1; y <= V; y++) {// iterate through the list vertically (y)
		if (y != 5) { // ignore 5 and 9 as they are not accessible from certain locations
			if (y != 9)
				for (x = 1; x <= V; x++) { // iterate through the list horizontally (x)
					if (x != 5) // ignore 5 horizontally for now, we will add it later
						addDirectedEdge(exercise2, y, x);
				
				}
		}
		// add directed edges to 5
		if (y == 5) {
			addDirectedEdge(exercise2, y, 1);
			addDirectedEdge(exercise2, y, 2);
			addDirectedEdge(exercise2, y, 3);
			addDirectedEdge(exercise2, y, 4);
			addDirectedEdge(exercise2, y, 10);
		}
		// add directed edges to 9
		if (y == 9) {
			addDirectedEdge(exercise2, y, 1);
			addDirectedEdge(exercise2, y, 6);
			addDirectedEdge(exercise2, y, 7);
			addDirectedEdge(exercise2, y, 8);
			addDirectedEdge(exercise2, y, 9);
			addDirectedEdge(exercise2, y, 10);
		}
	}
	getNeighbours(exercise2, 1);
	printGraph(exercise2);
	x = 1;
	y = 1;
	int path_found = 0;
	int accessible = 1;
	int notallowed = 0;
	int steps = 0;
	while (!path_found) {
		printf("Finding path...");
		steps++;
		if (x == 6 && y == 1)
			path_found = 1;
	}
}