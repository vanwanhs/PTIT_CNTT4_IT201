// //
// // Created by Hikari on 23/06/2025.
// //
//
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    int indexLast = -1;
    printf ("enter length of array: ");
    scanf ("%d", &n);
    if (n < 0 ) {
        printf ("invalidate input!");
        return 0;
    }
    int arr[n];
    printf ("Enter array elements");
    printf("\n");
    for (int i = 0; i < n; i++) {
        scanf ("%d", &arr[i]);
    }
    printf("\n");
    int x;
    printf ("enter a number randam: ");
    scanf ("%d", &x);
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] == x) {
            indexLast = i;
            break;
        }
    }
    if (indexLast != -1) {
        printf ("%d ", indexLast);
    } else {
        printf ("no solution");
    }
    return 0;
}
