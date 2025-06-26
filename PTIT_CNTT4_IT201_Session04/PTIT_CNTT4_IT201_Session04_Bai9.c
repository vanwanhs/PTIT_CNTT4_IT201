//
// Created by Hikari on 26/06/2025.
//


#include <stdio.h>
#include <stdlib.h>
int binarySearch(int n[],int low, int high, int key) {
    // Điều kiện dừng khi không tìm thaaSY
    if (low > high) {
        return -1;
    }
    //điều kiện dừng khi tìm thấy
    int mid = (low + high) / 2;
    if (key == n[mid]) {
        return mid;
    }
    if (key > n[mid]) {
        binarySearch(n, low, mid - 1, key);
    } else {
        binarySearch(n, mid + 1, high, key);
    }
}
int main() {

    return 0;
}
