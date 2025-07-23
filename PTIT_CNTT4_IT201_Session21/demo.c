//
// Created by Hikari on 23/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int *));
    return graph;
}
int main() {

    return 0;
}
