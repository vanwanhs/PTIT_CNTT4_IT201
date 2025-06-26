//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
int printf1Ton(int n) {
    if (n == 0) {
        return 0;
    }
    printf1Ton(n-1);
    printf("%d\n", n);

}
int main() {
    int n;
    printf("Please enter the number: ");
    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }
    printf1Ton(n);
    return 0;
}
