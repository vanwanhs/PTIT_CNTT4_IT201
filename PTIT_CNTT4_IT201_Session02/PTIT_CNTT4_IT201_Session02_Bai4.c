#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    int posi = -1;

    while (n < 0 || n > 100) {
        printf("Please enter a number between 0 and 100: ");
        scanf("%d", &n);
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    while (posi < 0 || posi >= n) {
        printf("Please enter the position to update (0 to %d): ", n - 1);
        scanf("%d", &posi);
    }

    printf("Old value at position %d: %d\n", posi, arr[posi]);
    int newValue;
    printf("Enter new value for position %d: ", posi);
    scanf("%d", &newValue);

    arr[posi] = newValue;

    printf("Array after update:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
