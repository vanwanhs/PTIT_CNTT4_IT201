#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, position;

    printf("Please enter the length of array: ");
    scanf("%d", &n);
    while (n <= 0 || n > 100) {
        printf("Please enter a valid length of array (1 - 100): ");
        scanf("%d", &n);
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Please enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Please enter the position to delete (1 to %d): ", n);
    scanf("%d", &position);
    while (position < 1 || position > n) {
        printf("Invalid position. Please enter again (1 to %d): ", n);
        scanf("%d", &position);
    }

    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    free(arr);
    return 0;
}
