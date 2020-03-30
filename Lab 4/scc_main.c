/* Created by Eduardo Wallén & Junior Corazza */
#include "scc.h"

int main() {
	/*
	
				0
			  /   \
			 1 --> 2--->6
			 ^     ^
			 |	   |
			 |	   |
			 3<----4
			  \    ^
			   \   |
			    \  |
				  >5
	*/
	Graph_s* graph = CreateGraph_scc(7);
	addEdge(graph, 0, 1);
	addEdge(graph, 1, 0);
	addEdge(graph, 0, 2);
	addEdge(graph, 2, 0);
	addEdge(graph, 1, 2);
	addEdge(graph, 4, 2);
	addEdge(graph, 3, 1);
	addEdge(graph, 4, 3);
	addEdge(graph, 3, 5);
	addEdge(graph, 5, 4);
	addEdge(graph, 2, 6);
	print_scc(graph);
}