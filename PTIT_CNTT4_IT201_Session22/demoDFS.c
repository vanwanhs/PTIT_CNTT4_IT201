//
// Created by Hikari on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;

// Hàm tạo đồ thị mới
Graph *newGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;

    // Cấp phát ma trận V x V
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->matrix[i][j] = 0; // Khởi tạo không có cạnh
        }
    }
    return graph;
}

// Thêm cạnh vào đồ thị vô hướng
void addEdge(Graph *graph, int u, int v) {
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

// Hàm hỗ trợ DFS
void DFSUtil(Graph *graph, int src, int *visited) {
    // B1: In ra đỉnh src và đánh dấu đã thăm
    printf("%d ", src);
    visited[src] = 1;

    // B2: Duyệt tất cả đỉnh trong đồ thị
    for (int i = 0; i < graph->V; i++) {
        // B3: Nếu có đường đi từ src đến i và đỉnh i chưa được thăm
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            // B4: Gọi đệ quy DFS từ đỉnh i
            DFSUtil(graph, i, visited);
        }
    }
}

// Hàm khởi động DFS từ 1 đỉnh bất kỳ
void DFS(Graph *graph, int start) {
    int *visited = (int *)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) visited[i] = 0;

    DFSUtil(graph, start, visited);

    free(visited);
}

int main() {
    int V = 5;
    Graph *graph = newGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("Duyet DFS bat dau tu dinh 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
