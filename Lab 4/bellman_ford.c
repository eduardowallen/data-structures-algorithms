#include "bellman_ford.h"

Graph* creategraph(int V, int E) {
	Graph* graphs = (Graph*)malloc(sizeof(Graph));
	graphs->V = V;
	graphs->E = E;
	graphs->edges = (Edge*)malloc(graphs->E * sizeof(Edge));
	return graphs;
}

int Bellman_Ford(Graph* graphs, int S) {
	int E = graphs->E;
	int V = graphs->V;
	int flag = 1;
	int i, j, u, v, w;
	int distance[999], parent[999];
	// Init-single source, all v is set to infinity except source node
	for (i = 0; i < graphs->V; i++) {
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	distance[S] = 0;
	// For all (u,v) in E, call Relax(u,v,w)
	for (i = 1; i <= V - 1; i++)
	{
		for (j = 0; j < E; j++)
		{
			u = graphs->edges[j].u;
			v = graphs->edges[j].v;
			w = graphs->edges[j].w;
			if (distance[v] > distance[u] + w) {
				distance[v] = distance[u] + w;
				parent[v] = u;
			}
		}
	}
	// Check if negative cycle exists   
	for (i = 0; i < E; i++)
	{
		u = graphs->edges[i].u;
		v = graphs->edges[i].v;
		w = graphs->edges[i].w;
		if (distance[v] > distance[u] + w)
			flag = 0;
	}
	if (flag)
		for (i = 1; i < V; i++)
			printf("Shortest path from source node to vertex %d. Cost: %d | Parent = %d\n", i, distance[i], parent[i]);
	return flag;
}