//
// Created by Hikari on 27/06/2025.
//

#include <stdio.h>

int findMin(int arr[], int n) {
    if (n == 1) return arr[0];
    int min_rest = findMin(arr, n - 1);
    return (arr[n - 1] < min_rest) ? arr[n - 1] : min_rest;
}

int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int max_rest = findMax(arr, n - 1);
    return (arr[n - 1] > max_rest) ? arr[n - 1] : max_rest;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minVal = findMin(arr, n);
    int maxVal = findMax(arr, n);

    printf("%d, %d\n", minVal, maxVal);

    return 0;
}
