//
// Created by Acer on 16/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int *mallocArray(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    int *myArray = mallocArray(10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    free(myArray);
    return 0;
}
// do vòng lặp chạy từ i => n nên tổng số vòng lặp là n lần
// mà mooxi lần gán giá trị arr[i] = i
// nên suy ra độ phức tạp của không gian là O(n)