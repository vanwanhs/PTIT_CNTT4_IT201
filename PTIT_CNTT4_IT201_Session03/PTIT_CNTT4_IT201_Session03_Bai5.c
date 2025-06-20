//
// Created by Hikari on 19/06/2025.
//


# include <stdio.h>
# include <stdlib.h>

int main() {
    int rows, cols;
    do{
        printf("Please enter rows of array: ");
        scanf("%d",&rows);
        printf("Please enter cols of array: ");
        scanf("%d",&cols);
    }while(rows <=0 || cols<=0);
    int **arr=(int **)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++) {
        arr[i]=(int *)malloc(cols*sizeof(int));
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("Please enter the element [%d][%d] in Array: ", i+1, j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    if (rows != cols) {
        printf("Sorry! Array size is not same as array size!");
        return 0;
    }
    int mainDiagonal=0;
    int secondaryDiagonal=0;
    for(int i=0;i<rows;i++) {
        mainDiagonal+=arr[i][i];
        secondaryDiagonal+=arr[i][cols-1-i];
    }
    printf("Main diagonal is %d\n",mainDiagonal);
    printf("Second diagonal is %d",secondaryDiagonal);
    for(int i=0;i<rows;i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
