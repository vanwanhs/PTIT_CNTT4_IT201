#include <stdio.h>
#include <stdlib.h>  // cần cho malloc và free

int main() {
    int n = -1;

    while (n < 0 || n >= 100) {
        printf("Please enter a number (0 <= n < 100): ");
        scanf("%d", &n);
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Please enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int number;
    printf("Please enter the number you want to search: ");
    scanf("%d", &number);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            count++;
        }
    }

    printf("Number %d appears %d time(s).\n", number, count);

    free(arr);

    return 0;
}
