//
// Created by Hikari on 19/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,position,number;
    printf("please enter length of Array: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("please enter length of Array: ");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc((n+1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("please enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("please enter element in array");
    scanf("%d", &number);

    printf("please enter position: ");
    scanf("%d", &position);
    while (position < 0 || position > n) {
        printf("please enter position: ");
        scanf("%d", &position);
    }
    for (int i = n; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = number;
    n++;
    printf("Array after add: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}