#include <stdio.h>
#include "graph.h"
#include "algorithmsGraph.h"

int main() {
	graph g1 = {0,NULL};
	graphDir *g2 = NULL;
	graphDir *g3 = NULL;
	graph g4 = {0,NULL};
	graphDir *g5 = NULL;
	new_Graph(&g1,9);
	new_Graph(&g4,4);
	g2 = new_GraphDir(5,8);
	g3 = new_GraphDir(4,4);
	g5 = new_GraphDir(4,6);
	//grafo 1
	add_weightEdge(&g1,0,1,4);
	add_weightEdge(&g1,0,7,8);
	add_weightEdge(&g1,1,7,11);
	add_weightEdge(&g1,1,2,8);
	add_weightEdge(&g1,2,8,2);
	add_weightEdge(&g1,2,5,4);
	add_weightEdge(&g1,2,3,7);
	add_weightEdge(&g1,3,4,9);
	add_weightEdge(&g1,3,5,14);
	add_weightEdge(&g1,4,5,10);
	add_weightEdge(&g1,5,6,2);
	add_weightEdge(&g1,6,7,1);
	add_weightEdge(&g1,6,8,6);
	add_weightEdge(&g1,7,8,7);
	print_matrizAdjGraph(g1);
	print_Graph(g1);
	dijkstra(g1,0,8,true);
	//dijkstra(g,3,5,true);
	//grafo 2
	// add edge 0-1 (or A-B in above figure) 
    g2->edge[0].src = 0; 
    g2->edge[0].dest = 1; 
    g2->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    g2->edge[1].src = 0; 
    g2->edge[1].dest = 2; 
    g2->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    g2->edge[2].src = 1; 
    g2->edge[2].dest = 2; 
    g2->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    g2->edge[3].src = 1; 
    g2->edge[3].dest = 3; 
    g2->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    g2->edge[4].src = 1; 
    g2->edge[4].dest = 4; 
    g2->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    g2->edge[5].src = 3; 
    g2->edge[5].dest = 2; 
    g2->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    g2->edge[6].src = 3; 
    g2->edge[6].dest = 1; 
    g2->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    g2->edge[7].src = 4; 
    g2->edge[7].dest = 3; 
    g2->edge[7].weight = -3; 
	print_GraphDir(g2);
	BellmanFord(g2,0,3,true);
	//grafo 3
	g3->edge[0].src = 0;
	g3->edge[0].dest = 1;
	g3->edge[0].weight = 5;
	
	g3->edge[1].src = 1;
	g3->edge[1].dest = 2;
	g3->edge[1].weight = 3;
	
	g3->edge[2].src = 2;
	g3->edge[2].dest = 3;
	g3->edge[2].weight = 1;
	
	g3->edge[3].src = 0;
	g3->edge[3].dest = 3;
	g3->edge[3].weight = 10;
	print_GraphDir(g3);
	floydWarshall(g3);
	//grafo 4
	add_Edge(&g4,0,1);
	add_Edge(&g4,0,2);
	add_Edge(&g4,1,2);
	add_Edge(&g4,2,3);
	add_Edge(&g4,3,3);
	print_matrizAdjGraph(g4);
	BFS(g4,2);
	DFS(g4,2);
	//grafo 5
	g5->edge[0].src = 0;
	g5->edge[0].dest = 1;
	g5->edge[0].weight = 0;
	
	g5->edge[1].src = 0;
	g5->edge[1].dest = 2;
	g5->edge[1].weight = 0;
	
	g5->edge[2].src = 1;
	g5->edge[2].dest = 2;
	g5->edge[2].weight = 0;
	
	g5->edge[3].src = 2;
	g5->edge[3].dest = 0;
	g5->edge[3].weight = 0;
	
	g5->edge[4].src = 2;
	g5->edge[4].dest = 3;
	g5->edge[4].weight = 0;
	
	g5->edge[5].src = 3;
	g5->edge[5].dest = 3;
	g5->edge[5].weight = 0;
	print_GraphDir(g5);
	BFS_graphDir(g5,2);
	DFS_graphDir(g5,2);
	//liberar memoria utilizada
	delete_Graph(&g1);
	delete_GraphDir(&g2);
	delete_GraphDir(&g3);
	delete_Graph(&g4);
	delete_GraphDir(&g5);
	return 0;
}

