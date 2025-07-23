//
// Created by Hikari on 23/07/2025.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph -> matrix = (int **)malloc(V * sizeof(int *));
    for (int i=0;i<V;i++) {
        graph -> matrix[i] = (int *)malloc(V * sizeof(int));
        for (int j=0;j<V;j++) {
            graph -> matrix[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(Graph *graph, int strartNode, int endNode) {
    if (strartNode >= 0 && strartNode <graph -> V && endNode >= 0 && endNode <graph -> V) {
        graph -> matrix[strartNode][endNode] = 1;
    } else {
        printf("Invalid Edge");
    }
}
void printGraph(Graph *graph) {
    printf("[\n");
    for (int i=0;i<graph -> V;i++) {
        printf(" ");
        for (int j=0;j<graph -> V;j++) {
            printf(" %d", graph -> matrix[i][j]);
            if (j < graph -> V - 1) printf(",");
        }
        printf(" ]\n");
    }
    printf("]\n\n");
}
int main() {
int V = 3;
    Graph *graph = createGraph(V);
    int startNode = 1;
    int endNode = 2;
    addEdge(graph, startNode, endNode);
    printf("Graph after adding edge: \n");
    printGraph(graph);
    return 0;
}
