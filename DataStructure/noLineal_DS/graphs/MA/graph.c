#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void new_Graph(graph* g, const unsigned v) {
	g->nodes = v;
	g->adj = (int**) malloc(sizeof(int*) * (size_t)v);
	if(!g->adj) {
		printf("Error. No se pudo reservar espacio en memoria.\n");
		exit(EXIT_FAILURE);
	}
	for(unsigned i = 0; i < v; ++i) {
		g->adj[i] = (int*) malloc(sizeof(int) * (size_t)v);
		if(!g->adj[i]) {
			printf("Error. No se pudo reservar espacio en memoria.\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for(unsigned i = 0; i < v; ++i) {
		for(unsigned j = 0; j < v; ++j)
			g->adj[i][j] = 0;
	}	
}

void delete_Graph(graph* g) {
	for(unsigned i = 0; i < g->nodes; ++i) {
		free(g->adj[i]);
	}
	
	free(g->adj);
	g->nodes = 0;
	g->adj = NULL;
}

void add_Edge(graph* g, const unsigned u, const unsigned v) {
	g->adj[u][v] = (int)v+1;
	g->adj[v][u] = (int)u+1;
}

void add_weightEdge(graph* g, const unsigned u, const unsigned v, const int w) {
	g->adj[u][v] = w;
	g->adj[v][u] = w;
}

void print_Graph(graph g) {
	if(g.adj != NULL) {
		for(unsigned i = 0; i < g.nodes; ++i) {
			printf("Vertices conectados al Vertice %u:\n[ ",i);
			for(unsigned j = 0; j < g.nodes; ++j) {
				if(g.adj[i][j] != 0) {
					printf("%u ",j);
				}
			}
			printf("]\n");
		}
	}
}

void print_matrizAdjGraph(graph g) {
	if(g.adj != NULL) {
		printf("Matriz de Adyacencia:\n");
		for(unsigned i = 0; i < g.nodes; ++i) {
			for(unsigned j = 0; j < g.nodes; ++j)
				printf("%3d ",g.adj[i][j]);
			printf("\n");
		}
	}
}

graphDir* new_GraphDir(const unsigned v, const unsigned e) {
	graphDir* g = malloc(sizeof(graphDir));
	if(!g)
		printf("Error. No se pudo asignar memoria dinamicamente.\n"), exit(EXIT_FAILURE);
	g->V = v;
	g->E = e;
	g->edge = malloc(sizeof(Edge) * (size_t)e);
	if(!g->edge)
		printf("Error. No se pudo asignar memoria dinamicamente.\n"), exit(EXIT_FAILURE);
	
	return g;
}

void print_GraphDir(graphDir* g) {
	if(!g)
		return;
	printf("\nEdges\t\tweight\n");
	for(size_t i = 0; i < g->E; ++i)
		printf("%u -> %u\t\t%4d\n",g->edge[i].src,g->edge[i].dest,g->edge[i].weight);
}

void delete_GraphDir(graphDir** g) {
	if(!*g)
		return;
	
	free((*g)->edge);
	(*g)->edge = NULL;
	free(*g);
	*g = NULL;
}
