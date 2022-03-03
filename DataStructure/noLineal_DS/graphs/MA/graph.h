#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph {
	unsigned nodes;
	int **adj;
} graph;

typedef struct Edge {
	unsigned src, dest;
	int weight;
} Edge;

typedef struct graphDir {
	unsigned V,E;
	Edge *edge;
} graphDir;

void new_Graph(graph* g, const unsigned v);
void add_Edge(graph* g, const unsigned u, const unsigned v);
void add_weightEdge(graph* g, const unsigned u, const unsigned v, const int w);
void print_Graph(graph g);
void print_matrizAdjGraph(graph g);
void delete_Graph(graph* g);
graphDir* new_GraphDir(const unsigned v, const unsigned e);
void print_GraphDir(graphDir* g);
void delete_GraphDir(graphDir** g);
#endif	//GRAPH_H
