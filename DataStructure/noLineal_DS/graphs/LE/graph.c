#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

Graph* new_Graph(unsigned v) {
	Graph* g = malloc(sizeof(Graph));
	assert(g != NULL);
	g->V = v;
	g->adj = malloc(sizeof(lista) * (size_t)v);
	assert(g->adj != NULL);
	for(size_t i = 0; i < v; ++i)
		g->adj[i] = NULL;
	return g;
}

void delete_Graph(Graph** g) {
	if(*g != NULL) {
		for(size_t i = 0; i < (*g)->V; ++i) {
			clear_list(&(*g)->adj[i]);
			(*g)->adj[i] = NULL;
		}
		free((*g)->adj);
		(*g)->adj = NULL;
		(*g)->V = 0;
		free(*g);
		*g = NULL;
	}
}

void print_Graph(Graph* g) {
	if(!g)
		return;
	for(size_t i = 0; i < g->V; ++i) {
		printf("\nVertices conectados al vertice %lu\n",i);
		print_list(g->adj[i]);
	}
}

void add_Edge(Graph* g, unsigned u, unsigned v) {
	assert(g != NULL);
	insert_nodo(&(g->adj[u]),v,0);
	insert_nodo(&(g->adj[v]),u,0);
}

void add_edgeWeight(Graph* g, unsigned u, unsigned v, int w) {
	assert(g != NULL);
	insert_nodo(&(g->adj[u]),v,w);
	insert_nodo(&(g->adj[v]),u,w);
}

void print_edgesGraph(Graph* g) {
	if(!g)
		return;
	lista aux = NULL;
	printf("\nEdges\t\tWeight\n");
	for(size_t i = 0; i < g->V; ++i) {
		aux = g->adj[i];
		while(aux) {
			printf("%lu -> %u\t\t%4d\n",i,aux->dest,aux->weight);
			aux = aux->sig;
		}
	}
}

GraphD* new_GraphD(unsigned v, unsigned e) {
	GraphD* g = malloc(sizeof(GraphD));
	assert(g != NULL);
	g->V = v;
	g->E = e;
	g->idx_e = 0;
	g->edge = malloc(sizeof(Edge) * (size_t)e);
	assert(g->edge != NULL);
	
	return g;
}

void delete_GraphD(GraphD** g) {
	if(*g != NULL) {
		free((*g)->edge);
		(*g)->edge = NULL;
		(*g)->V = (*g)->E = 0;
		free(*g);
		*g = NULL;
	}
}

void print_GraphD(GraphD* g) {
	if(!g)
		return;
	printf("\nEdges\t\tWeight\n");
	for(size_t i = 0; i < g->E; ++i)
		printf("%u -> %u\t\t%4d\n",g->edge[i].src,g->edge[i].dest,g->edge[i].weight);
}

void add_EdgeD(GraphD* g, unsigned u, unsigned v, int weight) {
	assert((g != NULL) && (g->idx_e < g->E));
	g->edge[g->idx_e].src = u;
	g->edge[g->idx_e].dest = v;
	g->edge[g->idx_e].weight = weight;
	(g->idx_e)++;
}
