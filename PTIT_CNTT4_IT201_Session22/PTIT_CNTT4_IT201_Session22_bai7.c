//
// Created by Hikari on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** graph, int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = graph[u];
    graph[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = graph[v];
    graph[v] = nodeU;
}

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX - 1) {
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int value = q->items[q->front];
        q->front++;
        return value;
    }
    return -1;
}

void BFS(Node** graph, int start, int* visited, int v) {
    Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        Node* temp = graph[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(&q, neighbor);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int v, e;
    printf("Enter number of vertices (0 < v < 100): ");
    scanf("%d", &v);
    printf("Enter number of edges (0 < e < 100): ");
    scanf("%d", &e);

    if (v <= 0 || v >= 100 || e <= 0 || e >= 100) {
        printf("Invalid input.\n");
        return 1;
    }

    Node** graph = (Node**)malloc(v * sizeof(Node*));
    for (int i = 0; i < v; i++) {
        graph[i] = NULL;
    }

    printf("Enter %d edges (format: vertex1 vertex2):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < v && w >= 0 && w < v) {
            addEdge(graph, u, w);
        } else {
            printf("Edge (%d, %d) is invalid. Skipped.\n", u, w);
        }
    }

    int start;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    int visited[MAX] = {0};
    printf("BFS traversal starting from vertex %d: ", start);
    BFS(graph, start, visited, v);
    printf("\n");

    for (int i = 0; i < v; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}
