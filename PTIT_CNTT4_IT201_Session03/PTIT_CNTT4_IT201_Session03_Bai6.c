//
// Created by Hikari on 19/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    do {
        printf("Please enter the length in array: \n");
        scanf("%d", &n);
    }while(n<0 || n >= 1000);
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter array element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    do {
        printf("How many elements do you want in the array: ");
        scanf("%d", &m);
    } while(m<0);
    arr = (int*)realloc(arr,(m+n)*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = n; i < (n+m); i++) {
        printf("Enter array element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("Array after add elements: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
