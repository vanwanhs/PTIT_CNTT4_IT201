//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
int printfNumFirstToNumSecond(int numFirst, int numSecond) {
    if (numFirst == numSecond) {
        return numFirst;
    }
    return printfNumFirstToNumSecond(numFirst + 1, numSecond) + numFirst;
}
int main() {
    int numFirst, numSecond;
    printf("Please enter the first number: ");
    scanf("%d", &numFirst);
    printf("Please enter the second number: ");
    scanf("%d", &numSecond);
    if (numFirst > numSecond) {
        printf("%d is greater than %d", numFirst, numSecond);
        return 0;
    }
    int result = printfNumFirstToNumSecond(numFirst, numSecond);
    printf("%d", result);
    return 0;
}
