//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[], int left, int right) {
    while (left < right && !isalnum(str[left])) left++;
    while (left < right && !isalnum(str[right])) right--;

    if (left >= right) return 1;

    if (tolower(str[left]) != tolower(str[right]))
        return 0;

    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input, 0, strlen(input) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

