#ifndef GRAPHALG_H
#define GRAPHALG_H
#include <stdbool.h>
#include "graph.h"

void BFS(graph g, unsigned s);
void BFS_graphDir(graphDir* g, unsigned s);
void DFS(graph g, unsigned s);
void DFS_graphDir(graphDir* g, unsigned s);
size_t dijkstra(graph g, const unsigned orig, const unsigned dest, bool show_path);
int BellmanFord(graphDir* g, const unsigned orig, const unsigned dest, bool show_path);
void floydWarshall(graphDir* g);
//kruskal
//prim
#endif //GRAPHALG_H
