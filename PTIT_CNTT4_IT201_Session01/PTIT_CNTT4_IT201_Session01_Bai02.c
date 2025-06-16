//
// Created by Acer on 16/06/2025.
//
#include <stdio.h>
void printfDouble() {
    int i = 1;
    while (i <= 10) {
        printf("%d\n",i);
        i *= 2;
    }
}
int main() {
    printfDouble();
    return 0;
}
// sau khi chạy bài ta thấy
// i < n (=10) , O(n^2) giá trị của i tăng theo cấp số nhân 2
// nên suy ra độ phức tạp vòng lapwj sấp sỉ O(log n)