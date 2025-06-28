//
// Created by Hikari on 27/06/2025.
//

#include <stdio.h>
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    printf("enter input: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("invalidate input\n");
    } else {
        int sum = sumOfDigits(n);
        printf("%d\n", sum);
    }

    return 0;
}

