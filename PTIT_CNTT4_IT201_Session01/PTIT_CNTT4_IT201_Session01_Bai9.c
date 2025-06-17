//
// Created by Acer on 16/06/2025.
//
#include <stdio.h>
int main() {
    int n;
    printf("Please enter a number n x n:\n");
    scanf("%d", &n);
    int arr[n][n];

    printf("Please enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The array is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int sum = 0;
    printf("duong cheo chinh");
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];
        printf("%d ", arr[i][i]);
    }
    printf("The sum is %d\n", sum);
    return 0;
}
//  Vì ta sự dụng hai vòng for loong nhau nên mức độ phức tạp thời gian của mảng hai chiều
// sẽ là O(n^2)
// Ta có tổng đường chéo chính chính là đường mà so vòng lặp phụ thuộc vào n và car mảng nên t sẽ có mức độ
// khoong gian tổng thể của tính tổng đường chéo chính là o(n^2)
