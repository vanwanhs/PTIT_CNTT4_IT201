//
// Created by Hikari on 19/06/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("Khong hop le, moi nhap lại: ");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter array element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d\n",i+1, arr[i]);
    }
    free(arr);
    return 0;
}