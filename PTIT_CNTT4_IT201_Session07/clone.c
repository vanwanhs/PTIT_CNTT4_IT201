//
// Created by Hikari on 01/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n);
void printfArr(int arr[], int n);
int main() {

    return 0;
}
void insertionSort(int arr[], int n) {
    int i,j ;
    for (int i = 1; i < n; i++) {
        j = arr[i];
        while ( j > 0 && arr[j-1] >j) {
            arr[j]= arr[j-1];
            j--;
        }
    }
    arr[j]=j;
}
void printfArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
}
