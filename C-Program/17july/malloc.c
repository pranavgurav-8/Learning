#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char argv){
    int size;
    int *dynamicarray;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    dynamicarray=(int *)malloc(size*sizeof(int));
    if(dynamicarray==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d elements:\n",size);
    for(int i=0;i<size;i++){
        scanf("%d",&dynamicarray[i]);
    }
    printf("Array elements: ");
    for(int i=0;i<size;i++){
        printf("%d\n",dynamicarray[i]);
    }
    printf("\n");
    int newSize;
    printf("Enter the new size\n");
    scanf("%d",&newSize);
    dynamicarray=(int*)realloc(dynamicarray,newSize*sizeof(int));
    printf("Enter the additional %d elements:\n",newSize-size);
    for(int i=size;i<newSize;i++){
        scanf("%d",&dynamicarray[i]);
    }
    printf("Updated array elements\n");
    for(int i=0;i<newSize;i++){
        printf("%d\n",dynamicarray[i]);
    }
    printf("\n");
    free(dynamicarray);
    return 0;
}