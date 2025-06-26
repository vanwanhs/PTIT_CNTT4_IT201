//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

int sum1ToN(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sum1ToN(n - 1);
}
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("khong hop le");
        return 0;
    }
    int sum = sum1ToN(n);
    printf("The sum of %d is %d", n, sum);
    return 0;
}
