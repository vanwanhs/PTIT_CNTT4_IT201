//
// Created by Hikari on 20/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
int n,search;
   do {
       printf("Please enter number of elements: \n");
       scanf("%d", &n);
   }while(n<=0);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Please enter array elements: \n");
        scanf("%d", &arr[i]);
    }
    printf("Please enter number of elements: \n");
    scanf("%d", &search);
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Tim thay");
            return 0;
        } else {
            printf("Khong tim thay");
        }
    }
    return 0;
}
