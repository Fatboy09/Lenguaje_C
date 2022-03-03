#include <stdio.h>
#include "graph.h"
#include "algorithmsGraph.h"

int main()
{
	Graph *g1 = NULL;
	GraphD *g2 = NULL;
	Graph *g3 = NULL;
	GraphD *g4 = NULL;
	GraphD *g5 = NULL;
	Graph *g6 = NULL;
	g1 = new_Graph(5);
	g2 = new_GraphD(5,8);
	g3 = new_Graph(4);
	g4 = new_GraphD(4,6);
	g5 = new_GraphD(4,4);
	g6 = new_Graph(9);
	//grafo 1
	add_Edge(g1,0,1);
	add_Edge(g1,0,4);
	add_Edge(g1,1,2);
	add_Edge(g1,1,3);
	add_Edge(g1,1,4);
	add_Edge(g1,2,3);
	add_Edge(g1,3,4);
	print_Graph(g1);
	print_edgesGraph(g1);
	//grafo 2
	add_EdgeD(g2,0,1,-1);
	add_EdgeD(g2,0,2,4);
	add_EdgeD(g2,1,2,3);
	add_EdgeD(g2,1,3,2);
	add_EdgeD(g2,1,4,2);
	add_EdgeD(g2,3,2,5);
	add_EdgeD(g2,3,1,1);
	add_EdgeD(g2,4,3,-3);
	print_GraphD(g2);
	BellmanFord(g2,0,3,true);
	//grafo 3
	add_Edge(g3,0,1);
	add_Edge(g3,0,2);
	add_Edge(g3,1,2);
	add_Edge(g3,2,3);
	add_Edge(g3,3,3);
	BFS(g3,2);
	DFS(g3,2);
	//grafo 4
	add_EdgeD(g4,0,1,0);
	add_EdgeD(g4,0,2,0);
	add_EdgeD(g4,1,2,0);
	add_EdgeD(g4,2,0,0);
	add_EdgeD(g4,2,3,0);
	add_EdgeD(g4,3,3,0);
	BFS_graphDir(g4,2);
	DFS_graphDir(g4,2);
	//grafo 5
	add_EdgeD(g5,0,3,10);
	add_EdgeD(g5,0,1,5);
	add_EdgeD(g5,1,2,3);
	add_EdgeD(g5,2,3,1);
	floydWarshall(g5);
	//grafo 6
	add_edgeWeight(g6,0,1,4);
	add_edgeWeight(g6,0,7,8);
	add_edgeWeight(g6,1,2,8);
	add_edgeWeight(g6,1,7,11);
	add_edgeWeight(g6,2,3,7);
	add_edgeWeight(g6,2,8,2);
	add_edgeWeight(g6,2,5,4);
	add_edgeWeight(g6,3,4,9);
	add_edgeWeight(g6,3,5,14);
	add_edgeWeight(g6,4,5,10);
	add_edgeWeight(g6,5,6,2);
	add_edgeWeight(g6,6,7,1);
	add_edgeWeight(g6,6,8,6);
	add_edgeWeight(g6,7,8,7);
	dijkstra(g6,0,6,true);
	//liberar memoria utilizada
	delete_Graph(&g1);
	delete_GraphD(&g2);
	delete_Graph(&g3);
	delete_GraphD(&g4);
	delete_GraphD(&g5);
	delete_Graph(&g6);
	return 0;
}
