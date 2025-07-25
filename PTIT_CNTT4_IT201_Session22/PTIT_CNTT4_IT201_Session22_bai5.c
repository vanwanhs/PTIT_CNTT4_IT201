//
// Created by Hikari on 24/07/2025.
//

#include <stdio.h>

int main() {
    int n, v;
    int matrix[100][100] = {0};

    printf("Enter number of vertices (0 < n < 100): ");
    scanf("%d", &n);
    printf("Enter number of edges (0 < v < 100): ");
    scanf("%d", &v);

    if (n <= 0 || n >= 100 || v <= 0 || v >= 100) {
        printf("Invalid value.\n");
        return 1;
    }

    printf("Enter %d edges (format: vertex1 vertex2):\n", v);
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < n && w >= 0 && w < n) {
            matrix[u][w] = 1;
            matrix[w][u] = 1;
        } else {
            printf("Edge (%d, %d) is invalid. Skipped.\n", u, w);
        }
    }

    int k, count = 0;
    printf("Enter vertex to check: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Invalid vertex.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (matrix[k][i] == 1) {
            count++;
        }
    }

    printf("Number of adjacent vertices to vertex %d is: %d\n", k, count);

    return 0;
}

