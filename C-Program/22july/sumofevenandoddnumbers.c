#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr,n,i,evensum=0,oddsum=0;
    printf("Enter number\n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
    }
    for(i=0;i<n;i++){
        if(*(ptr+i)%2==0){
            evensum+=ptr[i];
        
        }
        else{
            oddsum+=ptr[i];
             
             
        }
        // printf("%d\n",ptr[i]);
    }
    printf("%d\n",evensum);
    printf("%d\n",oddsum);
    free(ptr);
    // printf("%d\n",ptr[3]);
    // // ptr[6]=3;
    // printf("%d\n",ptr[6]);

}