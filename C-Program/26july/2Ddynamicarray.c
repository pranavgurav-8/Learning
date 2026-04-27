#include<stdio.h>
#include<stdlib.h>
void createdynamicarray(int ***arr,int row,int col){
    (*arr)=(int **)malloc(sizeof(int*)*row);
    for(int i=0;i<col;i++){
        (*arr)[i]=(int *)malloc(sizeof(int)*col);
    }
    
}
void insertintodynamicarray(int **arr,int row,int col){
    int val;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            printf("Enter\n");
            scanf("%d",(*(arr+i)+j));
            // *(*(arr+i)+j)=val;
        }
    }
}

int main(){
    int **arr;
    int row=3,col=3;
    createdynamicarray(&arr,row,col);
   *(*(arr+0)+0)=3;
    printf("%d\n",*(*(arr+0)+0));
    insertintodynamicarray(arr,row,col);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d",*(*(arr+i)+j));
        }
    }
}