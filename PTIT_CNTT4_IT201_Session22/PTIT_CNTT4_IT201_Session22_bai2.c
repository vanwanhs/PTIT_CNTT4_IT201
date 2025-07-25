//
// Created by Hikari on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

Graph* newGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void addEdge(Graph* graph, int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = graph->adjList[u];
    graph->adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = graph->adjList[v];
    graph->adjList[v] = nodeU;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d:", i);
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    Graph* graph = newGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}
