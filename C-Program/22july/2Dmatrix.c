#include<stdio.h>
#include<stdlib.h>

int main(){
    int rows1,cols1,rows2,cols2;
    printf("enter the number of rows and columns for 1st matrix:");
    scanf("%d %d",&rows1,&cols1);
    int **arr1=(int **)malloc(rows1*sizeof(int*));
    for(int i=0;i<rows1;i++){
        arr1[i]=(int*)malloc(rows1*sizeof(int));
    }
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            printf("enter the element");
            scanf("%d",(*(arr1+i)+j));
        }
    }
// For second matrix
    printf("enter the number of rows and columns for second matrix:");
    scanf("%d %d",&rows2,&cols2);
    int **arr2=(int**)malloc(rows2*sizeof(int*));
    for(int i=0;i<cols2;i++){
        arr2[i]=(int*)malloc(cols2*sizeof(int));
    }

    // *(*(arr1+i)+j)
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            printf("enter the element\n");
            scanf("%d",&arr2[i][j]);
        }
    }

//for multiplication matrix
    int **mul=(int**)malloc(rows1*sizeof(int*));
    for(int i=0;i<cols1;i++){
        mul[i]=(int*)malloc(cols1*sizeof(int));
    }
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            mul[i][j]=0;
            for(int k=0;k<cols1;k++){
                mul[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            printf("%d\n",mul[i][j]);
        }
    }
}