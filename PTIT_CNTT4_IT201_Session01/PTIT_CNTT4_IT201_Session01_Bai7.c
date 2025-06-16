//
// Created by Acer on 16/06/2025.
//
 #include <stdio.h>

int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,2,3,3,3,4,2,23,234,5,11,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int counted[100]={0};
    for (int i = 0; i < n; i++) {
        if (counted[i]) continue;
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
        }
        printf(" gia tri %d xuat hien so lan %d\n",arr[i],count);
    }
    return 0;
}
// ta sử dụng vòng lặp ngoài chạy tuwf i = 0 đến n -1 ;
// với mỗi vòng i ta chạy từ i + 1 đến n - 1 => số lần chạy giảm dần
// do đó nên thời gian chạy sẽ là o(n^2)

// do sử dụng mảng phụdđể kiểm tradđêm số phần tử chưa không phụ thuộc vào giá trị phần tử trong mảng
// chỉ cần một ô nhớ cho phần tử đếm chưa tỉ lệ thuật theo n vì vậy nên không gian của
// thuật toán 0(n)
