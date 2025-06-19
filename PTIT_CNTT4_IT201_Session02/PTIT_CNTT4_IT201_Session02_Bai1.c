//
// Created by Acer on 17/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
   do {
       printf("Please enter array elements:\n");
       scanf("%d", &n);
   } while(n<0 || n >= 100);
  int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int numberMax;
    for (int i = 0; i < n; i++) {
        printf("Please enter array elements: \n");
        scanf("%d", &arr[i]);
        if (arr[i] > numberMax) {
            numberMax = arr[i];
        }
    }
    printf("Number of elements in the array is: %d\n", numberMax);
    free(arr);
   return 0;
}
