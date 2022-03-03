#include <stdio.h>
#include <limits.h>
#include "algorithmsGraph.h"
#include "queue.h"
#include "minHeap.h"

void BFS(Graph* g, unsigned s) {
	unsigned V = g->V;
	bool visited[V];
	
	for(size_t i = 0; i < V; ++i)
		visited[i] = false;
	
	queue *q = newQueue();
	lista aux = NULL;
	visited[s] = true;
	enqueue(&q,s);
	printf("\nBFS algorithm:\n");
	while(!isEmpty_queue(q)) {
		s = peek(q);
		printf("%d ",s);
		dequeue(&q);
		aux = g->adj[s];
		while(aux) {
			if(!visited[aux->dest]) {
				visited[aux->dest] = true;
				enqueue(&q,aux->dest);
			}
			aux = aux->sig;
		}
	}
	printf("\n");
	destroy_queue(&q);
}

void BFS_graphDir(GraphD* g, unsigned s) {
	unsigned E = g->E;
	unsigned V = g->V;
	Graph *aux = new_Graph(V);
	for(size_t i = 0; i < E; ++i)
		insert_nodo(&(aux->adj[g->edge[i].src]),g->edge[i].dest,g->edge[i].weight);
	BFS(aux,s);
	delete_Graph(&aux);
}

void DFS_rec(unsigned s, bool visited[], Graph* g, unsigned V) {
	visited[s] = true;
	printf("%u ",s);
	lista aux = g->adj[s];
	while(aux) {
		if(!visited[aux->dest])
			DFS_rec(aux->dest,visited,g,V);
		aux = aux->sig;
	}
}

void DFS(Graph* g, unsigned s) {
	unsigned V = g->V;
	bool visited[V];
	
	for(size_t i = 0; i < V; ++i)
		visited[i] = false;
	printf("\nDFS algorithm:\n");
	DFS_rec(s,visited,g,V);
	printf("\n");
}

void DFS_graphDir(GraphD* g, unsigned s) {
	unsigned E = g->E;
	unsigned V = g->V;
	Graph* aux = new_Graph(V);
	for(size_t i = 0; i < E; ++i)
		insert_nodo(&(aux->adj[g->edge[i].src]),g->edge[i].dest,g->edge[i].weight);
	DFS(aux,s);
	delete_Graph(&aux);
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

size_t dijkstra(Graph* g, const unsigned orig, const unsigned dest, bool show_path) {
	unsigned V = g->V;
	size_t dist[V];
	int parent[V];
	lista aux = NULL;
	unsigned u = 0, v = 0;
	
	parent[orig] = -1;
	MinHeap* minHeap = new_MinHeap((int)V);
	for(size_t v = 0; v < V; ++v) {
		dist[v] = UINT_MAX;
		minHeap->array[v] = new_MinHeapNode(v,dist[v]);
		minHeap->pos[v] = v;
	}
	minHeap->array[orig] = new_MinHeapNode(orig,dist[orig]);
	minHeap->pos[orig] = orig;
	dist[orig] = 0;
	decrease_key(minHeap,orig,dist[orig]);
	minHeap->size = (int)V;
	while(!isEmpty_MinHeap(minHeap)) {
		dataType_minHeap minHeapNode = extractMin(minHeap);
		u = minHeapNode->v;
		aux = g->adj[u];
		while(aux) {
			v = aux->dest;
			if(isInMinHeap(minHeap,v) && dist[u] != UINT_MAX && (unsigned)aux->weight + dist[u] < dist[v]) {
				parent[v] = (int)u;
				dist[v] = (unsigned)aux->weight + dist[u];
				decrease_key(minHeap,v,dist[v]);
			}
			aux = aux->sig;
		}
	}
	delete_MinHeap(&minHeap);
	printSolution_Dijkstra(dist,V);
	if(show_path)
		printf("\nPath:\n%u ",orig), printPath(parent,(int)dest), printf("\nDistancia: %lu\n",dist[dest]);
	
	return dist[dest];
}

void printSolution_BellmanFord(int* dist, const size_t v) {
	printf("\nVertice\t\tDistancia desde el origen\n");
	for(size_t i = 0; i < v; ++i)
		printf("%4lu\t\t%13d\n",i,dist[i]);
}

int BellmanFord(GraphD* g, const unsigned orig, const unsigned dest, bool show_path) {
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

void floydWarshall(GraphD* g) {
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
