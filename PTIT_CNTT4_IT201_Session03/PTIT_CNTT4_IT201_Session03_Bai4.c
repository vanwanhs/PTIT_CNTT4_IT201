//
// Created by Hikari on 19/06/2025.
//


# include <stdio.h>
# include <stdlib.h>

int main() {
    int rows,cols;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of cols: ");
    scanf("%d",&cols);
    while(rows <=0 || cols<=0) {
        printf("Please enter rows of array: ");
        scanf("%d",&rows);
        printf("Please enter columns of array: ");
        scanf("%d",&cols);
    }
    int **arr=(int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++) {
        arr[i]=(int *)malloc(cols*sizeof(int));
    }
    int max,min;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("Please enter element [%d][%d] of the Array: ", i+1 ,j+1);
            scanf("%d",&arr[i][j]);
            if (i == 0 && j == 0) {
                max = min = arr[i][j];
            } else {
                if (arr[i][j] > max) max = arr[i][j];
                if (arr[i][j] < min) min = arr[i][j];
            }
        }
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("The number is the biggest in the Array: %d\n",max);
    printf("The number is the smallest in the Array: %d\n",min);
    for(int i=0;i<rows;i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
