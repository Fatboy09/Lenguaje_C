#include <stdio.h>
#include <limits.h>
#include "algorithmsGraph.h"
#include "queue.h"

void BFS(graph g, unsigned s) {
	unsigned V = g.nodes;
	bool visited[V];
	
	for(size_t i = 0; i < V; ++i)
		visited[i] = false;
	
	queue *q = newQueue();
	visited[s] = true;
	enqueue(&q,s);
	printf("\nBFS algorithm:\n");
	while(!isEmpty_queue(q)) {
		s = peek(q);
		printf("%d ",s);
		dequeue(&q);
		for(size_t i = 0; i < V; ++i) {
			if(g.adj[s][i] != 0) {
				if(!visited[i]) {
					visited[i] = true;
					enqueue(&q,i);
				}
			}
		}
	}
	printf("\n");
	destroy_queue(&q);
}

void BFS_graphDir(graphDir* g, unsigned s) {
	graph aux = {0,NULL};
	unsigned E = g->E;
	unsigned V = g->V;
	new_Graph(&aux,V);
	for(size_t i = 0; i < E; ++i)
		aux.adj[g->edge[i].src][g->edge[i].dest] = 1;
	BFS(aux,s);
	delete_Graph(&aux);
}

void DFS_rec(unsigned s, bool visited[], graph g, unsigned V) {
	visited[s] = true;
	printf("%u ",s);
	for(size_t i = 0; i < V; ++i) {
		if(g.adj[s][i] != 0) {
			if(!visited[i]) {
				DFS_rec(i,visited,g,V);
			}
		}
	}
}

void DFS(graph g, unsigned s) {
	unsigned V = g.nodes;
	bool visited[V];
	
	for(size_t i = 0; i < V; ++i)
		visited[i] = false;
	printf("\nDFS algorithm:\n");
	DFS_rec(s,visited,g,V);
	printf("\n");
}

void DFS_graphDir(graphDir* g, unsigned s) {
	graph aux = {0,NULL};
	unsigned E = g->E;
	unsigned V = g->V;
	new_Graph(&aux,V);
	for(size_t i = 0; i < E; ++i)
		aux.adj[g->edge[i].src][g->edge[i].dest] = 1;
	DFS(aux,s);
	delete_Graph(&aux);
}

size_t minDistance(size_t* dist, bool* sptSet, const size_t V) {
	size_t min = UINT_MAX, min_idx;
	
	for(size_t v = 0; v < V; ++v) {
		if(!sptSet[v] && dist[v] <= min)
			min = dist[v], min_idx = v;
	}
	
	return min_idx;
}

void printSolution_Dijkstra(size_t* dist, const size_t v) {
	printf("\nVertice\t\tDistancia desde el origen\n");
	for(size_t i = 0; i < v; ++i)
		printf("%4lu\t\t%13lu\n",i,dist[i]);
}

void printPath(int* parent, int j) {
	if(parent[j] == -1)
		return;
	printPath(parent,parent[j]);
	printf("%d ",j);
}

size_t dijkstra(graph g, const unsigned orig, const unsigned dest, bool show_path) {
	unsigned V = g.nodes;
	size_t dist[V];
	bool sptSet[V];
	int parent[V];
	
	parent[orig] = -1;
	for(size_t i = 0; i < V; ++i) {
		dist[i] = UINT_MAX;
		sptSet[i] = false;
	}
	dist[orig] = 0;
	for(size_t k = 0; k < V - 1; ++k) {
		size_t u = minDistance(dist,sptSet,V);
		sptSet[u] = true;
		for(size_t v = 0; v < V; ++v) {
			if(!sptSet[v] && g.adj[u][v] && dist[u] != UINT_MAX && dist[u] + (size_t)g.adj[u][v] < dist[v]) {
				parent[v] = (int)u;
				dist[v] = dist[u] + (size_t)g.adj[u][v];
			}
		}
	}
	printSolution_Dijkstra(dist,V);
	if(show_path)
		printf("\nPath:\n%u ", orig), printPath(parent,(int)dest), printf("\nDistancia: %lu\n",dist[dest]);
	
	return dist[dest];
}

void printSolution_BellmanFord(int* dist, const size_t v) {
	printf("\nVertice\t\tDistancia desde el origen\n");
	for(size_t i = 0; i < v; ++i)
		printf("%4lu\t\t%13d\n",i,dist[i]);
}

int BellmanFord(graphDir* g, const unsigned orig, const unsigned dest, bool show_path) {
	unsigned V = g->V;
	unsigned E = g->E;
	int dist[V];
	int parent[V];
	
	parent[orig] = -1;
	for(size_t i = 0; i < V; ++i)
		dist[i] = INT_MAX;
	
	dist[orig] = 0;
	for(size_t i = 0; i < V - 1; ++i) {
		for(size_t j = 0; j < E; ++j) {
			unsigned u = g->edge[j].src;
			unsigned v = g->edge[j].dest;
			int weight = g->edge[j].weight;
			if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
				parent[v] = (int)u;
				dist[v] = dist[u] + weight;
			}
		}
	}
	for(size_t i = 0; i < E; ++i) {
		unsigned u = g->edge[i].src;
		unsigned v = g->edge[i].dest;
		int weight = g->edge[i].weight;
		if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("El grafo contiene un peso negativo ciclico\n.");
			return INT_MAX;
		}
	}
	
	printSolution_BellmanFord(dist,V);
	if(show_path)
		printf("\nPath:\n%u ",orig), printPath(parent,(int)dest), printf("\nDistancia: %d\n",dist[dest]);
		
	return dist[dest];
}

void printSolution_FloydWarshall(const size_t V, int dist[][V]) {
	printf("\nLa matriz de abajo muestra las distancias mas cortas entre cada par de vertices\n");
	for(size_t i = 0; i < V; ++i) {
		for(size_t j = 0; j < V; ++j) {
			if(dist[i][j] == INT_MAX)
				printf("%7s","INF");
			else
				printf("%7d",dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void floydWarshall(graphDir* g) {
	size_t V = g->V;
	int dist[V][V];
	
	for(size_t i = 0; i < V; ++i) {
		for(size_t j = 0; j < V; ++j) {
			if(i == j)
				dist[i][i] = 0;
			else
				dist[i][j] = INT_MAX;
		}
	}
	
	for(size_t i = 0; i < g->E; ++i)
		dist[g->edge[i].src][g->edge[i].dest] = g->edge[i].weight;
	
	for(size_t k = 0; k < V; ++k) {
		for(size_t i = 0; i < V; ++i) {
			for(size_t j = 0; j < V; ++j) {
				if(dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution_FloydWarshall(V,dist);
}
