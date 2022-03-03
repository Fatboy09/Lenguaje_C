#ifndef GRAPHALG_H
#define GRAPHALG_H
#include <stdbool.h>
#include "graph.h"

void BFS(Graph* g, unsigned s);
void BFS_graphDir(GraphD* g, unsigned s);
void DFS(Graph* g, unsigned s);
void DFS_graphDir(GraphD* g, unsigned s);
size_t dijkstra(Graph* g, const unsigned orig, const unsigned dest, bool show_path);
int BellmanFord(GraphD* g, const unsigned orig, const unsigned dest, bool show_path);
void floydWarshall(GraphD* g);
//kruskal
//prim
#endif //GRAPHALG_H
