#include "graph.h"

///Function that creates a Graph object
///
///Arguments:		num_vertices		-	the number of verticies in the graph
///Returnvalue:		Graph*			-	returns a pointer to the Graph object
///										created
///Error handling:		If the memoryallocation for the Graph object fails
///						NULL is returned
Graph* createGraph(int num_vertices) {
	Graph* return_graph = malloc(sizeof(Graph));

	if (return_graph == NULL) {
		printf("Could not allocate memory for Graph object!");
		return NULL;
	}
	return_graph->size = num_vertices;

	return_graph->vertices = malloc(sizeof(GVert) * num_vertices);
	if (return_graph->vertices == NULL) {
		printf("Could not allocate memory for Graph verticies!");
		return NULL;
	}

	return_graph->s_dist_arr = malloc(sizeof(float) * return_graph->size);
	if (return_graph->s_dist_arr == NULL) {
		printf("Could not allocate memory for Graph shortest distance array!");
		return NULL;
	}

	return_graph->pred_arr = malloc(sizeof(int) * return_graph->size);
	if (return_graph->pred_arr == NULL) {
		printf("Could not allocate memory for Graph predecessor array!");
		return NULL;
	}

	return_graph->finished_stack = init_stack();

	for (int current_vert = 0; current_vert < num_vertices; current_vert++) {
		return_graph->vertices[current_vert].edgeList = initLinkedList(NULL, 0);
		return_graph->vertices[current_vert].key = current_vert;
	}

	return return_graph;
}

///Function that returns the number of verticies in the graph
///
///Arguments:		input_graph		-	pointer to the graph object
///Returnvalue:		int				-	the number of verticies in the graph
///										if the graph obj is NULL, 0 is returned
int getNumVertices(Graph* input_graph) {
	if (input_graph != NULL) {
		return input_graph->size;
	}
	else {
		return 0;
	}
}

///Function that returns the number of edges in the graph
///
///Arguments:		input_graph		-	pointer to the graph object
///Returnvalue:		int				-	the number of edges in the graph
///										if the graph obj is NULL, 0 is returned
int getNumEdges(Graph* input_graph) {
	int num_edges = 0;
	if (input_graph != NULL) {
		linkedList* tmp_ll = NULL;
		printf("Size: %d\n", input_graph->size);
		for (int a = 0; a < input_graph->size; a++) {
			tmp_ll = input_graph->vertices[a].edgeList;
			num_edges += getListSize(tmp_ll);
		}
	}
	return num_edges;
}

///Function that returns all in and outgoing neighbours of a vertex
///
///Arguments:		input_graph		-	pointer to the graph object
///Returnvalue:		search_vert		-	the vertex we want to find 
///										neighbours for
///	
linkedList* getNeighbors(Graph* input_graph, GVert* search_vert) {
	linkedList* return_ll = initLinkedList(NULL, 0);
	linkedList* in_ll = getInNeighbors(input_graph, search_vert);
	linkedList* out_ll = getOutNeighbors(input_graph, search_vert);

	ll_Node* current_vert = in_ll->sentinel->next;
	ll_Node* tmp_vert = NULL;
	while (current_vert != in_ll->sentinel) {
		tmp_vert = createLLNode(current_vert->key);
		insert(return_ll, tmp_vert);
		current_vert = current_vert->next;
	}
	current_vert = out_ll->sentinel->next;
	while (current_vert != out_ll->sentinel) {
		if (!search(return_ll, current_vert->key)) {
			tmp_vert = createLLNode(current_vert->key);
			insert(return_ll, tmp_vert);
			current_vert = current_vert->next;
		}
	}
	return return_ll;
}

///Function that returns all incomming neighbours of a vertex
///
///Arguments:		input_graph		-	pointer to the graph object
///Returnvalue:		search_vert		-	the vertex we want to find 
///										neighbours for
///
linkedList* getInNeighbors(Graph* input_graph, GVert* search_vert) {
	linkedList* return_list = initLinkedList(NULL, 0);
	ll_Node* tmp_node = NULL;
	int num_edges = 0;
	for (int a = 0; a < input_graph->size; a++) {
		if (search(input_graph->vertices[a].edgeList, search_vert->key)) {
			num_edges++;
			tmp_node = createLLNode(a);
			insert(return_list, tmp_node);
		}
	}
	return return_list;
}

///Function that returns all outgoing neighbours of a vertex
///
///Arguments:		input_graph		-	pointer to the graph object
///Returnvalue:		search_vert		-	the vertex we want to find 
///										neighbours for
///
linkedList* getOutNeighbors(Graph* input_graph, GVert* search_vert) {
	linkedList* return_list = initLinkedList(NULL, 0);
	ll_Node* tmp_vert = search_vert->edgeList->sentinel->next;
	ll_Node* insert_vert = NULL;
	while (tmp_vert != search_vert->edgeList->sentinel) {
		insert_vert = createLLNode(tmp_vert->key);
		insert(return_list, insert_vert);
		tmp_vert = tmp_vert->next;
	}
	return return_list;
}


///Function that add a directed edge between two verticies the 
///Direction is from vert_one to vert_two
///
///Arguments:		vert_one		-	pointer to origin vertex
///					vert_two		-	pointer to the target vertex
///Returnvalue:		int			-	returns the 1 of everything is OK
///									If something went wrong return -1
int addDirectedEdge(GVert* vert_one, GVert* vert_two) {
	float weight = 1;//different weights not implemented.
	if (!search(vert_one->edgeList, vert_two->key)) { //To avoid dublicate edges
		ll_Node* add_edge = malloc(sizeof(ll_Node));
		if (add_edge == NULL) {
			return 0;
		}
		add_edge->key = vert_two->key;
		add_edge->weight = weight;
		insert(vert_one->edgeList, add_edge);
		return 1;
	}
	else {
		return 0;
	}
}

///Function that add an undirected edge between two verticies
///It actually adds two directeted edges between two verticies
///in opposite directions
///
///Arguments:		vert_one		-	pointer to one vertex
///					vert_two		-	pointer to another vertex
///Returnvalue:		int			-	returns the 1 of everything is OK
///									If something went wrong return -1
int addUndirectedEdge(GVert* vert_one, GVert* vert_two) {
	float weight = 1; //different weights not implemented
	int return_val = 0;
	if (!search(vert_one->edgeList, vert_two->key)) {
		ll_Node* add_edge = malloc(sizeof(ll_Node));
		if (add_edge == NULL) {
			return 0;
		}
		add_edge->key = vert_two->key;
		add_edge->weight = weight;
		insert(vert_one->edgeList, add_edge);
	}

	if (!search(vert_two->edgeList, vert_two->key)) {
		ll_Node* add_edge = malloc(sizeof(ll_Node));
		if (add_edge == NULL) {
			return 0;
		}
		add_edge->key = vert_one->key;
		add_edge->weight = weight;

		insert(vert_two->edgeList, add_edge);
	}

	return 1;
}

///Function that test if two edges are connected
///
///Arguments:		vert_one		-	pointer to one vertex
///					vert_two		-	pointer to another vertex
///Returnvalue:		int			-	returns the 1 of edge exists
///									else returns -1
int hasEdge(GVert* vert_one, GVert* vert_two) {
	if (search(vert_one->edgeList, vert_two->key) || search(vert_two->edgeList, vert_one->key)) {
		return 1;
	}
	else {
		return 0;
	}
}

///Function that prints out an adjacencie-matrix of the graph
///
///Arguments:		print_graph	-	pointer to the graph to be displayed
///					
///Returnvalue:		void
void printGraphMatrix(Graph* print_graph) {
	int x;
	printf("       ");
	for (x = 0; x < print_graph->size; x++)
		printf("%d", x);
	printf("\n---------------------------\n");
	for (int y = 0; y < print_graph->size; y++) {
		printf("  %d  | ", y);
		for (x = 0; x < print_graph->size; x++) {
			if (&print_graph->vertices[y]) {
				if (search(print_graph->vertices[y].edgeList, x)) {
					printf("1");
				}
				else {
					printf("0");
				}
			}
		}
		printf("\n\n\n");
	}
}

///Bredth-First_search
///
///
///Arguments:		graph		-	pointer to the graphobject
///					start_vert	-	pointer to the vertex we want paths
///									from
///Returnvalue:		float		-	returns the and array of distances
///									between the start vertex and all other
///									vertecies
float* graphBFS(Graph* graph, GVert* search_vert) {
	float* dist_arr = malloc(sizeof(float) * graph->size);
	if (dist_arr == NULL) {
		printf("Unable to allocate memory for distance array in BFS!");
		return NULL;
	}
	int* path_predecessor = malloc(sizeof(int) * graph->size);
	if (path_predecessor == NULL) {
		return NULL;
	}
	for (int vert_counter = 0; vert_counter < graph->size; vert_counter++) {
		dist_arr[vert_counter] = INFINITY;
		path_predecessor[vert_counter] = vert_counter;
	}
	dist_arr[search_vert->key] = 0;
	Queue* BFS_Queue = init_queue();
	enqueue(BFS_Queue, search_vert->key);
	int current_vert_val = 0;
	int num_ques = 0;
	while (!queue_empty(BFS_Queue)) {
		num_ques++;
		current_vert_val = dequeue(BFS_Queue);
		ll_Node* current_adj_vert = graph->vertices[current_vert_val].edgeList->sentinel->next;
		while (current_adj_vert != graph->vertices[current_vert_val].edgeList->sentinel) {
			if (dist_arr[current_adj_vert->key] == INFINITY) {
				dist_arr[current_adj_vert->key] = dist_arr[current_vert_val] + 1;
				path_predecessor[current_adj_vert->key] = current_vert_val;
				enqueue(BFS_Queue, current_adj_vert->key);
			}
			current_adj_vert = current_adj_vert->next;
		}
	}

	return dist_arr;
}

///Depth-First-Search function
///First half of the algoritm
///Function that calculates the distances between verticies using
/// the depth-fist-search algoritm
/// Implemented to be used to find Strongly-Connected-Components
///Arguments:		graph	-	pointer to graph object
///
///Returnvalue:		void
///									
void graphDFS(Graph* graph) {
	int current_vert;
	for (current_vert = 0; current_vert < graph->size; current_vert++) {
		graph->vertices[current_vert].color = VERT_COLOR_WHITE;
		graph->vertices[current_vert].predecessor = current_vert;
	}
	int time = 0;
	for (current_vert = 0; current_vert < graph->size; current_vert++) {
		if (graph->vertices[current_vert].color == VERT_COLOR_WHITE) {
			graphDFSVisit(graph, &graph->vertices[current_vert]);
		}
	}
}

///Depth-First-Search-Visit
///First half of the algoritm
///Function that calculates the distances between verticies using
/// the depth-fist-search algoritm
/// Implemented to be used to find Strongly-Connected-Components
///Arguments:		graph		-	pointer to graph object
///					visit_vert	-	
///
///Returnvalue:		void
///		
void graphDFSVisit(Graph* graph, GVert* visit_vert) {
	graph->time++;
	visit_vert->visit = graph->time;
	visit_vert->color = VERT_COLOR_GREY;
	ll_Node* current_edge = visit_vert->edgeList->sentinel->next;
	while (current_edge != visit_vert->edgeList->sentinel) {
		if (graph->vertices[current_edge->key].color == VERT_COLOR_WHITE) {
			graph->vertices[current_edge->key].predecessor = visit_vert->key;
			graphDFSVisit(graph, &graph->vertices[current_edge->key]);
		}
		current_edge = current_edge->next;
	}

	visit_vert->color = VERT_COLOR_BLACK;
	printf("%d, ", visit_vert->key);
	graph->time++;
	stack_push(graph->finished_stack, visit_vert->key);
	visit_vert->finished = graph->time;
}

///Function that resets the graph for single source search
///F
/// Implemented to be used to find Strongly-Connected-Components
///Arguments:		graph		-	pointer to graph object
///					start_vert	-	the vertex we want to start at.
///
///Returnvalue:		void
///
void initSignleSource(Graph* graph, int start_vert) {
	for (int a = 0; a < graph->size; a++) {
		graph->s_dist_arr[a] = INFINITY;
		graph->pred_arr[a] = -1;
	}
	graph->s_dist_arr[start_vert] = 0;
	while (!stack_empty(graph->finished_stack)) {
		stack_pop(graph->finished_stack);
	}
}

void relaxEdge(Graph* graph, GVert* from_vert, GVert* to_vert) {
	if (graph->s_dist_arr[to_vert->key] > (graph->s_dist_arr[from_vert->key] + search(graph->vertices[from_vert->key].edgeList, to_vert->key)->weight)) {
		graph->s_dist_arr[to_vert->key] = graph->s_dist_arr[from_vert->key] + search(graph->vertices[from_vert->key].edgeList, to_vert->key)->weight;
		graph->pred_arr[to_vert->key] = from_vert->key;
	}
}

void SCC(Graph* graph) {
	int start_vert = 0;
	initSignleSource(graph, start_vert);
	graphDFS(graph);
	Graph* t_graph = transverseGraph(graph);
	int current_vert;
	for (current_vert = 0; current_vert < t_graph->size; current_vert++) {
		t_graph->vertices[current_vert].color = VERT_COLOR_WHITE;
		t_graph->vertices[current_vert].predecessor = NULL;
	}
	t_graph->time = 0;
	int scc_num = 1;
	while (!stack_empty(graph->finished_stack)) {
		current_vert = stack_pop(graph->finished_stack);
		if (t_graph->vertices[current_vert].color == VERT_COLOR_WHITE) {
			printf("\nScc %d: ", scc_num);
			scc_num++;
			graphDFSVisit(t_graph, &t_graph->vertices[current_vert]);
		}

	}
}

Graph* transverseGraph(Graph* graph) {
	Graph* return_graph = createGraph(graph->size);
	linkedList* tmp_edgeList = NULL;
	ll_Node* tmp_node = NULL;
	for (int current_vert = 0; current_vert < graph->size; current_vert++) {
		tmp_edgeList = graph->vertices[current_vert].edgeList;
		tmp_node = tmp_edgeList->sentinel->next;
		while (tmp_node != tmp_edgeList->sentinel) {
			addDirectedEdge(&return_graph->vertices[tmp_node->key], &return_graph->vertices[current_vert]);
			tmp_node = tmp_node->next;
		}
	}
	return return_graph;
}
