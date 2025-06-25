//
// Created by Hikari on 25/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, target;
    printf ("Please enter the length of array: ");
    scanf ("%d", &n);
    if (n <= 0) {
        printf ("Invalid input\n");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf ("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int temp = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for ( int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int start = 0;
    int end = n - 1;
    printf ("Please enter the number to search for: ");
    scanf ("%d", &target);
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            printf ("%d found at index %d\n", target, mid);
            return 2;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    printf("no solution");
    return 0;
}
