//
// Created by Hikari on 27/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
void nhiPhan(int n) {
    if (n == 0) return;
    nhiPhan(n/2);
    printf("%d", n%2);
}
int main() {
    int n;
    printf("Please enter a number: ");
    scanf("%d", &n);
    if (n<=0) {
        return 0;
    }
    nhiPhan(n);
    return 0;
}
