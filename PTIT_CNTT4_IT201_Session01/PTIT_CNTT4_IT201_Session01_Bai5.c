//
// Created by Acer on 16/06/2025.
//
#include <stdio.h>

void sortBB(int arr[], int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {1,3,2,33,4,32,45,322};
    int length = sizeof(arr) / sizeof(arr[0]);
    sortBB(arr, length);
    printf("Mang sau khi sap xep\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
// sử dụng thuật toán sắp xếp nổi bọt so sánh hai số liền kề với nhau nếu số nào lớn hơn thì tiến lên phải
// lần lượt cho tới khi dãy số không còn hoán đổithifif dừng lại vì vậy độ phức tạp
// của sắp xếp sẽ là 0(n^2)