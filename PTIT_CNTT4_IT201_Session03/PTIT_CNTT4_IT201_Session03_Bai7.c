//
// Created by Hikari on 19/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    do {
        printf("Please enter rows of array: ");
        scanf("%d", &n);
        printf("Please enter colums of array:\n");
        scanf("%d", &m);
    }while(n<0 || n >= 100);
    int **arr= (int **)malloc(n * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Please enter element [%d][%d]: \n",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    int posi;
   do {
       printf("Please enter rows of array:\n");
       scanf("%d", &posi);
   }while (posi <= 0 || posi > n);
    int sum = 0;
    for (int i = 0; i < n; i++) {

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf(" \n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
