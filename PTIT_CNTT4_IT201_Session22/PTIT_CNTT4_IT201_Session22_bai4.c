//
// Created by Hikari on 24/07/2025.
//

#include <stdio.h>

int main() {
    int n;
    int matrix[100][100];
    int count = 0;

    printf("Enter number of vertices (0 < n < 100): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("Number of edges in the undirected graph: %d\n", count);

    return 0;
}
