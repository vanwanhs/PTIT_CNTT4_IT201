//
// Created by Hikari on 30/06/2025.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[1001];
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    if (strlen(str) == 0) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("str = \"%s\"\n", str);

    sortString(str);

    printf("str = \"%s\"\n", str);

    return 0;
}

