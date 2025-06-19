//
// Created by Acer on 17/06/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    do {
        printf("Please enter array elements:\n");
        scanf("%d", &n);
    } while(n<0 || n >= 100);
    int start=0;
    int end=n-1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        printf("please enter element %d in array: ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("array befor reverse");
    while (start < end) {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}