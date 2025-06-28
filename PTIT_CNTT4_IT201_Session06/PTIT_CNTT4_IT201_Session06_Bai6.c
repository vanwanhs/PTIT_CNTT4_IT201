//
// Created by Hikari on 27/06/2025.
//

#include <stdio.h>

int countWays(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    printf("Enter number of steps: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input\n");
    } else {
        int ways = countWays(n);
        printf("%d\n", ways);
    }

    return 0;
}
