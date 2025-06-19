//
// Created by Hikari on 19/06/2025.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Please enter the length of Array: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Invalid input, please enter again: ");
        scanf("%d", &n);
    }
    int *arr = malloc(sizeof(int) * n);

    int maxCount = 1;
    int mostNumber;
    for (int i = 0; i < n; i++) {
        printf("Please enter array number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int *counted = (int*)calloc(n,sizeof(int));
    for (int i = 0; i < n-1; i++) {
        if (counted[i]) continue;
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
            if (maxCount < count) {
                maxCount = count;
                mostNumber = arr[i];
            }
        }
    }
    printf("the element that appears is the most is %d", maxCount);
    free(arr);
    free(counted);
    return 0;
}