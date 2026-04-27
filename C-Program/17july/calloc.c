#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char *argv){
    int size;
    int *callocc;
    callocc=(int *)calloc(size,sizeof(int));
    if(callocc==NULL){
        printf("Memory not allocated\n");
    }
    printf("Enter the size\n");
    scanf("%d",&size);
    printf("Enter the elements\n");
    for(int i=0;i<size;i++){
        scanf("%d",&callocc[i]);
    }
    printf("ELEMENTS\n");
    for(int i=0;i<size;i++){
        printf("%d\n",callocc[i]);
    }

}