/* Created by Eduardo Wallén & Junior Corazza */
#include "bellman_ford.h"

int main() {
	Graph* graph1 = creategraph(4, 5);

	/*
				GRAPH 1
				0 -(3)-> 2
				| \	     |
			   (2) (5)  (2)
				|     \  |
				1-(-3)-> 3


	*/
	// 0 -> 2 with weight 3
	graph1->edges[0].u = 0;
	graph1->edges[0].v = 2;
	graph1->edges[0].w = 3;
	// 2 -> 3 with weight 2
	graph1->edges[1].u = 2;
	graph1->edges[1].v = 3;
	graph1->edges[1].w = 2;
	// 0 -> 3 with weight 5
	graph1->edges[2].u = 0;
	graph1->edges[2].v = 3;
	graph1->edges[2].w = 5;
	// 0 -> 1 with weight 2
	graph1->edges[3].u = 0;
	graph1->edges[3].v = 1;
	graph1->edges[3].w = 2;
	// 1 -> 3 with weight 3
	graph1->edges[4].u = 1;
	graph1->edges[4].v = 3;
	graph1->edges[4].w = -3;

	Bellman_Ford(graph1, 0);
	printf("\n");

	Graph* graph2 = creategraph(4, 4);
	/*
			GRAPH 2
			0 -(4)-> 2
			| 		 |
		   (3)      (1)
			|        |
			1 -(3)-> 3


	*/
	// 0 -> 2 with weight 4
	graph2->edges[0].u = 0;
	graph2->edges[0].v = 2;
	graph2->edges[0].w = 4;
	// 2 -> 3 with weight 1
	graph2->edges[1].u = 2;
	graph2->edges[1].v = 3;
	graph2->edges[1].w = 1;
	// 0 -> 1 with weight 3
	graph2->edges[2].u = 0;
	graph2->edges[2].v = 1;
	graph2->edges[2].w = 3;
	// 1 -> 3 with weight 3
	graph2->edges[3].u = 1;
	graph2->edges[3].v = 3;
	graph2->edges[3].w = 3;

	Bellman_Ford(graph2, 0);

	/*
	*** PROGRAM OM MAN VILL LÄGGA IN INPUT I PROGRAMMET, EXTRA ***
	int V, E, S; // Vertices, edges, source node
	printf("Enter number of vertices: ");
	scanf("%d", &V);
	printf("Enter number of edges: ");
	scanf("%d", &E);
	printf("Enter source node: ");
	scanf("%d", &S);
	int i;
	for (i = 0; i < E; i++) {
		printf("\nEnter edge %d properties Source, destination, weight respectively\n", i + 1);
		scanf("%d", &graph->edges[i].u);
		scanf("%d", &graph->edges[i].v);
		scanf("%d", &graph->edges[i].w);
	}
	Bellman_Ford(graph, S);
	*/
}