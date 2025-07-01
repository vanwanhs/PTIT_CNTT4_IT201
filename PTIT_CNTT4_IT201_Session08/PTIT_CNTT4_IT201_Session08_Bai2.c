//
// Created by Hikari on 01/07/2025.
//

#include <stdio.h>

int main() {
    int n, search, left = 0, right, mid, found = 0;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &search);
    right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == search) {
            printf("phan tu vi tri thu %d\n", mid + 1);
            found = 1;
            break;
        } else if (arr[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) printf("Khong ton tai phan tu\n");
    return 0;
}

