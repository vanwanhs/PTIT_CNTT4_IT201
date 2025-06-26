//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int sumOfArray(int arr[], int size) {
    if (size == 1) return arr[0];
    return arr[size - 1] + sumOfArray(arr, size - 1);
}

int main() {
    int n;
    printf("Length of Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Array Elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = sumOfArray(arr, n);
    printf("The sum of the given array is: %d\n", sum);
    return 0;
}
