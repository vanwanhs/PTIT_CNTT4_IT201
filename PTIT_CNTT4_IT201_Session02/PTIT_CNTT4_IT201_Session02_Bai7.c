//
// Created by Hikari on 19/06/2025.
//

#include <stdio.h>
#include <stdlib.h>
int main () {
    int n,number;
    printf("Enter the length of Array: ");
    scanf("%d", &n);
    while (n<0) {
        printf("Invalid Length, Please enter again: ");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Array Element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("Please enter random a number: ");
    scanf("%d", &number);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] + arr[j] == number) {
                printf("%d + %d = %d\n", arr[i], arr[j], number);
                return 0;
            } else {
                printf("Khong tim thay");
            }
        }
    }
    return 0;
}