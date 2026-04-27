#include<stdio.h>
#include<stdlib.h>
int main(){
    int rows=3,cols=4;
    //original matrix
    int **arr=(int **)malloc(rows*sizeof(int));
    for(int i=0;i<cols;i++){
        *(arr+i)=(int*)malloc(cols*sizeof(int));
    }
    //transpose matrix
    int **trans=(int **)malloc(rows*sizeof(int));
    for(int i=0;i<cols;i++){
        *(trans+i)=(int*)malloc(cols*sizeof(int));
    }
//read the elements into original matrix
    for(int i=0;i<rows;i<i++){
        for(int j=0;j<cols;j++){
           scanf("%d",(*(arr+i)+j));
        }
    }
//display
    for(int i=0;i<rows;i<i++){
        for(int j=0;j<cols;j++){
           printf("%d ",(*(*(arr+i)+j)));
        }
        printf("\n");
    }


    printf("\n\n");

    //copy into transpose matrix
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           (*(*(trans+j)+i))=(*(*(arr+i)+j));
        }
    }
    for(int i=0;i<cols;i<i++){
        for(int j=0;j<rows;j++){
           printf("%d ",(*(*(trans+i)+j)));
        }
        printf("\n");
    }
}