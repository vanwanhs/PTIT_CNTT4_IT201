//
// Created by Hikari on 23/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
} Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;

    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->matrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int from, int to) {
    if (from >= 0 && from < graph->V && to >= 0 && to < graph->V) {
        graph->matrix[from][to] = 1;
    }
}

void printGraph(Graph *graph) {
    printf("[\n");
    for (int i = 0; i < graph->V; i++) {
        printf(" ");
        for (int j = 0; j < graph->V; j++) {
            printf(" %d", graph->matrix[i][j]);
            if (j < graph->V - 1) printf(",");
        }
        printf("\n");
    }
    printf("]\n\n");
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

int main() {
    int V = 3;
    Graph *graph = createGraph(V);

    printf("Initial graph:\n");
    printGraph(graph);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printf("Graph after adding edges:\n");
    printGraph(graph);

    freeGraph(graph);
    return 0;
}

