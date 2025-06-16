//
// Created by Acer on 16/06/2025.
//

#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int counted[100]={0};
    int maxCount = 1;
    int mostNumber;
    for (int i = 0; i < n; i++) {
        if (counted[i]) continue;
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
            if (maxCount < count) {
                maxCount = count;
                mostNumber = arr[i];
            }
        }
    }
    printf("so %d xuat hien nhieu nhat %d lan",mostNumber, maxCount);
    return 0;
}
// sử dụng hai vòng for để số lần xuất hieenj và so sánh lần lượt số lần xuất hiện nếu số nào lớn nhất
// thì lấy số đó ( tạo ra moojt biến so sánh và moojt bien xác định vị trí)
// tương tự như bài 6 ta có thể thấy độ phức tạp của thời gian là O(n^2)
// độ phức tạp không gian là o(n);