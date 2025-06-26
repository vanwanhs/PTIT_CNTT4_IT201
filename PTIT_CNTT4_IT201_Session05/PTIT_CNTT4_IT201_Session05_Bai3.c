//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
int printf1ToN(int n) {
    if (n < 1) {
        return 1;
    }
    return n * printf1ToN(n - 1);

}
int main() {
    int n;
    printf("Please enter the number: ");
    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }
    int result = printf1ToN(n);
    printf("%d\n", result);
    return 0;
}
