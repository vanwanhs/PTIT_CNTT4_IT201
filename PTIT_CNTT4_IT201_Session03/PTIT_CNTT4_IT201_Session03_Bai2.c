//
// Created by $Hikari on 19/06/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Please enter length of Array: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("Please enter length of Array again: ");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Please enter array number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int numberMax = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > numberMax) {
            numberMax = arr[i];
        }
    }
    printf("The maximum number is: %d", numberMax);
    free(arr);
    return 0;

}
