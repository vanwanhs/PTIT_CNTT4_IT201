#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;

Graph *newGraph(int V) {
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

void addEdge(Graph *graph, int u, int v) {
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    Graph *graph = newGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printMatrix(graph);

    for (int i = 0; i < n; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);

    return 0;
}
