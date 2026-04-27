#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr,n,sum=0;
    printf("enter the size of the array:");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("Memory not allocated\n");
    }
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
        // ptr++;
    }
    printf("\n\n");
    // for(int i=0;i<n;i++){
    //     printf("%d\n",*ptr++);
    //     // ptr++;
    // }

    for(int i=0;i<n;i++){
        sum+=*ptr;
        ptr++;
    }
    printf("sum is %d\n",sum);
}