//
// Created by Hikari on 23/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int **maxtrix;
}Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph -> V = V;
    graph -> maxtrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i<V;i++) {
        graph -> maxtrix[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j<V; j++) {
            graph -> maxtrix[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(Graph *graph, int u, int v) {
    if (u >= 0 && u < graph -> V && v >= 0 && v < graph -> V) {
        graph -> maxtrix[u][v] = 1;
        graph -> maxtrix[v][u] = 1;
    } else {
        printf("Invalid edge ");
    }
}
void printGraph(Graph *graph) {
    for (int i = 0; i< graph -> V; i++) {
        printf("[ ");
        for (int j = 0; j<graph -> V; j++) {
            printf("%d ",graph -> maxtrix[i][j]);
        }
        printf(" ]\n");
    }
}
void freeGraph(Graph *graph) {
    for (int i = 0; i<graph -> V; i++) {
        free(graph ->maxtrix[i]);
    }
    free(graph->maxtrix);
    free(graph);
}
int main() {
    int V = 3;
    Graph *graph = createGraph(V);
    printf("Intial graph:\n");
    printGraph(graph);
    int firstNode = 1;
    int secondNode = 2;
    addEdge(graph,firstNode,secondNode);
    printf("Graph after adding edge between %d and %d: \n");
    printGraph(graph);
    freeGraph(graph);
    return 0;
}
