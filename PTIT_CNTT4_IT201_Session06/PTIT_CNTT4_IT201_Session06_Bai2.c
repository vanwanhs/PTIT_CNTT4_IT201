//
// Created by Hikari on 27/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

int fibonacci(int k) {
    if (k == 1 || k == 2) return 1;
    return fibonacci(k - 1) + fibonacci(k - 2);
}

int main() {
    int n;
    printf("please input n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input invalidate\n");
        return 0;
    }

    for (int i = n; i >= 1; i--) {
        printf("%d", fibonacci(i));
        if (i > 1) printf(", ");
    }
    printf("\n");

    return 0;
}

