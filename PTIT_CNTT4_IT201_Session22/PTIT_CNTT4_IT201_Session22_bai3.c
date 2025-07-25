#include <stdio.h>
#include <stdlib.h>

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
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
}

void convertMatrixToList(int matrix[100][100], Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}

void printAdjList(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("Edge %d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

int main() {
    int n;
    int matrix[100][100];

    printf("input EDge (0 < n < 100): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("invalidate edge.\n");
        return 1;
    }

    printf("input matrix(%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Node** graph = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    convertMatrixToList(matrix, graph, n);
    printAdjList(graph, n);

    freeGraph(graph, n);
    return 0;
}