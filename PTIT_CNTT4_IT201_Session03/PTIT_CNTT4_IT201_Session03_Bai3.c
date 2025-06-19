//
// Created by Hikari on 19/06/2025.
//


# include <stdio.h>
# include <stdlib.h>

int main() {
    int n, sum;
    printf("Please enter length of Array: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("Please enter length of Array again: ");
        scanf("%d", &n);
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Please enter array number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i]%2==0) {
            sum += arr[i];
        }
    }
    printf("The sum of the array is %d", sum);
    free(arr);
    return 0;
}
