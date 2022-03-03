#ifndef GRAPHLE_H
#define GRAPHLE_H

#include "list.h"

typedef struct Edge{
	unsigned src,dest;
	int weight;
} Edge;

typedef struct Graph{
	unsigned V;
	lista *adj; 
} Graph;

typedef struct GraphD{
	unsigned V,E,idx_e;
	Edge *edge; 
} GraphD;

Graph* new_Graph(unsigned v);
void delete_Graph(Graph** g);
void print_Graph(Graph* g);
void add_Edge(Graph* g, unsigned u, unsigned v);
void add_edgeWeight(Graph* g, unsigned u, unsigned v, int weight);
void print_edgesGraph(Graph* g);

GraphD* new_GraphD(unsigned v, unsigned e);
void delete_GraphD(GraphD** g);
void print_GraphD(GraphD* g);
void add_EdgeD(GraphD* g, unsigned u, unsigned v, int weight);
#endif //GRAPHLE_H
