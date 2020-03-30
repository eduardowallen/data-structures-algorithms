#include <stdio.h>
#include "queue.h"
#include "graph.h"

#define MAP_WIDTH 12
#define MAP_HEIGHT 12

int main()
{
	printf("Excersice 1:\n  - Testing neighbors functions:\n");
	Graph* ex_1_graph = createGraph(5);

	addDirectedEdge(&ex_1_graph->vertices[0], &ex_1_graph->vertices[1]);
	addUndirectedEdge(&ex_1_graph->vertices[0], &ex_1_graph->vertices[3]);
	addDirectedEdge(&ex_1_graph->vertices[1], &ex_1_graph->vertices[2]);
	addDirectedEdge(&ex_1_graph->vertices[2], &ex_1_graph->vertices[4]);
	addDirectedEdge(&ex_1_graph->vertices[4], &ex_1_graph->vertices[1]);
	printf("\nIn neighbors:  ");
	//linkedList* neighbor_list = ;
	printList(getInNeighbors(ex_1_graph, &ex_1_graph->vertices[1]));
	printf("\nOut neighbors: ");

	printList(getOutNeighbors(ex_1_graph, &ex_1_graph->vertices[1]));
	printf("\nAll neighbors: ");
	printList(getNeighbors(ex_1_graph, &ex_1_graph->vertices[1]));
	printf("\n------------------------------------- \n");


	//Searching for the shortest path between vert (1,1) and (1,6)
	Graph* ex_2_graph = createGraph(MAP_WIDTH * MAP_HEIGHT);

	//Constructiong a 2 dimensional array to use as a base when I 
	//create edges to the graph
	int map_array[MAP_WIDTH][MAP_HEIGHT] = {
							{0,0,0,0,0,0,0,0,0,0,0,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,1,1,1,0,0,0,0,0,1,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,1,1,1,0,1,1,1,1,1,0},
							{0,1,0,0,0,0,1,1,1,1,1,0},
							{0,1,1,1,1,1,1,1,1,1,1,0},
							{0,0,0,0,0,0,0,0,0,0,0,0}
	};

	int current_vert;

	//Creating the edges
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			current_vert = (y * MAP_WIDTH) + x;
			if (map_array[y][x] == 1) { //Of the current vert is ok
				if (map_array[y][x - 1] == 1) { //If the vert to the left is ok, add edge
					addUndirectedEdge(&ex_2_graph->vertices[current_vert], &ex_2_graph->vertices[current_vert - 1]);
				}
				if (map_array[y][x + 1] == 1) { //If the vert to the right is ok, add edge
					addUndirectedEdge(&ex_2_graph->vertices[current_vert], &ex_2_graph->vertices[current_vert + 1]);
				}
				if (map_array[y - 1][x] == 1) { //If the vert above is ok, add edge
					addUndirectedEdge(&ex_2_graph->vertices[current_vert], &ex_2_graph->vertices[current_vert - MAP_WIDTH]);
				}
				if (map_array[y + 1][x] == 1) { //If the vert below is ok, add edge
					addUndirectedEdge(&ex_2_graph->vertices[current_vert], &ex_2_graph->vertices[current_vert + MAP_WIDTH]);
				}
			}
			else {
			}
		}
	}

	printf("Excercise 2\n");
	float* dist_arr = graphBFS(ex_2_graph, &ex_2_graph->vertices[13]);

	printf("Distance from 1 to 6 is %.0f\n\n", dist_arr[18]);

	//Here I test the SCC functionality for excersice 3.
	//I use the graph that Federico used during lecture and I get the expected result
	//However I was not able to come up with a smart way to make a good testing function
	//for this so it is what it is. Not pretty but it's working

	Graph* ex_3_graph = createGraph(10);
	if (ex_3_graph == NULL) {
		printf("ERROR!");
		return false;
	}

	//Adds the edges to the graph
	addDirectedEdge(&ex_3_graph->vertices[0], &ex_3_graph->vertices[1]);
	addDirectedEdge(&ex_3_graph->vertices[0], &ex_3_graph->vertices[2]);
	addDirectedEdge(&ex_3_graph->vertices[1], &ex_3_graph->vertices[0]);
	addDirectedEdge(&ex_3_graph->vertices[1], &ex_3_graph->vertices[3]);
	addDirectedEdge(&ex_3_graph->vertices[2], &ex_3_graph->vertices[3]);
	addDirectedEdge(&ex_3_graph->vertices[2], &ex_3_graph->vertices[4]);
	addDirectedEdge(&ex_3_graph->vertices[3], &ex_3_graph->vertices[0]);
	addDirectedEdge(&ex_3_graph->vertices[3], &ex_3_graph->vertices[5]);
	addDirectedEdge(&ex_3_graph->vertices[4], &ex_3_graph->vertices[5]);
	addDirectedEdge(&ex_3_graph->vertices[4], &ex_3_graph->vertices[6]);
	addDirectedEdge(&ex_3_graph->vertices[5], &ex_3_graph->vertices[4]);
	addDirectedEdge(&ex_3_graph->vertices[6], &ex_3_graph->vertices[5]);
	addDirectedEdge(&ex_3_graph->vertices[6], &ex_3_graph->vertices[7]);
	addDirectedEdge(&ex_3_graph->vertices[6], &ex_3_graph->vertices[8]);
	addDirectedEdge(&ex_3_graph->vertices[6], &ex_3_graph->vertices[9]);
	addDirectedEdge(&ex_3_graph->vertices[7], &ex_3_graph->vertices[9]);
	addDirectedEdge(&ex_3_graph->vertices[8], &ex_3_graph->vertices[9]);
	addDirectedEdge(&ex_3_graph->vertices[9], &ex_3_graph->vertices[8]);

	//Tada!!!
	printf("Excercise 3:\nStrongly connected Components\n");
	SCC(ex_3_graph);
}