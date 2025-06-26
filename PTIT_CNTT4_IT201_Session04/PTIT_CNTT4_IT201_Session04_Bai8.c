//
// Created by Hikari on 25/06/2025.
//


#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main() {
    int n, x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong khong hop le\n");
        return 0;
    }

    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Phan tu khong co trong mang");
    }

    printf("\n");
    return 0;
}

