//
// Created by Hikari on 30/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
void printfArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
}
void sortArr(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    if (n <=0) {
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Before sorting:\n");
    printfArr(arr,n);
    printf("\n");
    printf("After sorting:\n");
    sortArr(arr,n);
    printfArr(arr,n);
    return 0;
}
