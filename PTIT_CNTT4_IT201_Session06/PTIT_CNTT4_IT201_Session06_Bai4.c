//
// Created by Hikari on 27/06/2025.
//

#include <stdio.h>
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, to, aux);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
    } else {
        hanoi(n, 'A', 'B', 'C');
    }

    return 0;
}
