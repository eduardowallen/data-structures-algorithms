#include "graph.h"

#define MAP_WIDTH 12
#define MAP_HEIGHT 12

int main() {
	printf("--- Exercise 1 ---\n");
	printf("addDirectedEdge, addUndirectedEdge");
	Graph* ex1_graph = createGraph(5);
	addDirectedEdge(&ex1_graph->vertices[0], &ex1_graph->vertices[1]);
	addUndirectedEdge(&ex1_graph->vertices[0], &ex1_graph->vertices[3]);
	addDirectedEdge(&ex1_graph->vertices[1], &ex1_graph->vertices[2]);
	addDirectedEdge(&ex1_graph->vertices[2], &ex1_graph->vertices[4]);
	addDirectedEdge(&ex1_graph->vertices[4], &ex1_graph->vertices[1]);
	printf("\nIncoming neighbors:  ");
	printList(getInNeighbours(ex1_graph, &ex1_graph->vertices[1]));
	printf("\nOutgoing neighbors: ");
	printList(getOutNeighbours(ex1_graph, &ex1_graph->vertices[1]));
	printf("\nAll neighbors: ");
	printList(getNeighbours(ex1_graph, &ex1_graph->vertices[1]));

	printf("\n--- Exercise 2 ---\n");
	printf("Breadth First Search to find the shortest path to a vertice\n");
	printf("      1 2 3 4 5 6 7 8 9 10  \n");
	printf("    0,0,0,0,0,0,0,0,0,0,0,0\n");
	printf("1   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("2   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("3   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("4   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("5   0,1,1,1,1,0,0,0,0,0,1,0\n");
	printf("6   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("7   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("8   0,1,1,1,1,0,1,1,1,1,1,0\n");
	printf("9   0,1,0,0,0,0,1,1,1,1,1,0\n");
	printf("10  0,1,1,1,1,1,1,1,1,1,1,0\n");
	printf("    0,0,0,0,0,0,0,0,0,0,0,0\n");

	//Searching for the shortest path between vert (1,1) and (1,6)
	Graph* ex2_graph = createGraph(MAP_WIDTH * MAP_HEIGHT);

	// We create an array (width*height) to use as a base when creating edges in the graph
	int map_array[MAP_WIDTH][MAP_HEIGHT] = {
			/* 1 2 3 4 5 6 7 8 9 10 */
			{0,0,0,0,0,0,0,0,0,0,0,0},
	/* 1 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 2 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 3 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 4 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 5 */	{0,1,1,1,1,0,0,0,0,0,1,0},
	/* 6 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 7 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 8 */	{0,1,1,1,1,0,1,1,1,1,1,0},
	/* 9 */	{0,1,0,0,0,0,1,1,1,1,1,0},
	/* 10*/	{0,1,1,1,1,1,1,1,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0,0,0}
	};

	int current_vertice;

	// Creating the edges as we make our way through
	for (int y = 0; y < MAP_HEIGHT; y++)
		for (int x = 0; x < MAP_WIDTH; x++)
			if (map_array[y][x] == 1) {	// If the current vertice is accessible
				current_vertice = (y * MAP_WIDTH) + x;
				if (map_array[y][x - 1] == 1) // If the vertice to our left is accessible, add edge
					addUndirectedEdge(&ex2_graph->vertices[current_vertice], &ex2_graph->vertices[current_vertice - 1]);
				if (map_array[y][x + 1] == 1) // If the vertice to our right is accessible, add edge
					addUndirectedEdge(&ex2_graph->vertices[current_vertice], &ex2_graph->vertices[current_vertice + 1]);
				if (map_array[y - 1][x] == 1) // If the vertice above is accessible, add edge
					addUndirectedEdge(&ex2_graph->vertices[current_vertice], &ex2_graph->vertices[current_vertice - MAP_WIDTH]);
				if (map_array[y + 1][x] == 1) // If the vertice below is accessible, add edge
					addUndirectedEdge(&ex2_graph->vertices[current_vertice], &ex2_graph->vertices[current_vertice + MAP_WIDTH]);
			}


	float* dist_arr = BFS_Graph(ex2_graph, &ex2_graph->vertices[13]);
	printf("Distance from (1,2) to (6,1) is %.0f\n\n", dist_arr[18]);

}