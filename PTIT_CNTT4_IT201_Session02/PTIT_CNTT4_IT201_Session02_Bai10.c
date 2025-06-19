//
// Created by hikari on 19/06/2025.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
int n;
    printf("Please enter length of Array: ");
    scanf("%d", &n);
    while (n<= 0) {
        printf("Invalid input, try again\n");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Please enter array number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int *counted = (int*)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++) {
        if (counted[i]) continue;
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
        }
        printf("Phan tu %d xuat hien so lan la: %d\n", arr[i],count);
    }
    free(arr);
    free(counted);
    return 0;
}