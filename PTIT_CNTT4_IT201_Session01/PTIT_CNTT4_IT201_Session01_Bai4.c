//
// Created by Acer on 16/06/2025.
//
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum1, sum2;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++) {
        sum1 += arr[i];
    }
    sum2 = (length * (length+1)) / 2;
    printf("%d\n",sum1);
    printf("%d\n",sum2);

    return 0;
}

// theo như hai cách trên bạn có thể thấy không gian cua cách
// số 1 là 0(n) số vòng lặp duyệt tổng phần tử có trong mảng
// số 2 là O(1) được tính thẳng ra công thức toán học nên không cần vòng lặp