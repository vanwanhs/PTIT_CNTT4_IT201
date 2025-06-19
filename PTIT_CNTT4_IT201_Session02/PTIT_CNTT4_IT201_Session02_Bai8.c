//
// Created by Hikari on 19/06/2025.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Please enter the langth of Array: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Invalid length, Please enter again: ");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Please enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int flag = 1;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i]<=arr[j]) {
                flag == 0;
                break;
            }
            if (flag) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    printf("%d",arr[n-1]);
    free(arr);
    return 0;
}