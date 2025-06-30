//
// Created by Hikari on 30/06/2025.
//

#include <stdio.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf(" ]\n");
}

void customSort(int input[], int n, int result[]) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (input[i] < 0) {
            result[index++] = input[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (input[i] == 0) {
            result[index++] = input[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (input[i] > 0) {
            result[index++] = input[i];
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int arr[1000], sorted[1000];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");
    printArray(arr, n);

    customSort(arr, n, sorted);

    printf("After sorting:\n");
    printArray(sorted, n);

    return 0;
}
