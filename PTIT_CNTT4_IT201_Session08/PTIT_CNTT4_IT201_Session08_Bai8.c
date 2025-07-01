//
// Created by Hikari on 01/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    insertionSort(arr, n);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int linearIndex = linearSearch(arr, n, x);
    if (linearIndex != -1)
        printf("Tim kiem tuyen tinh: Tim thay tai vi tri %d\n", linearIndex + 1);
    else
        printf("Tim kiem tuyen tinh: Khong tim thay\n");

    int binaryIndex = binarySearch(arr, n, x);
    if (binaryIndex != -1)
        printf("Tim kiem nhi phan: Tim thay tai vi tri %d\n", binaryIndex + 1);
    else
        printf("Tim kiem nhi phan: Khong tim thay\n");

    return 0;
}
