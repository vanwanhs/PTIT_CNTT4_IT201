#include <stdio.h>

int main() {
    int n, search, found = 0;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &search);
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("vi tri thu %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) printf("Khong ton tai phan tu\n");
    return 0;
}
