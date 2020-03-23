#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge {
	int u;	// Source
	int v;	// Destination
	int w;	// Weight
} Edge;

typedef struct graph {
	int V;	// Vertices
	int E;	// Edges
	Edge* edges;
} Graph;
