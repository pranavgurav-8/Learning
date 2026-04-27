#include<stdio.h>
void deleteelement(int **p,int *len,int element){
    for(int i=0;i<*len;i++){
        if((*p)[i]==element){
            printf("%d\n",(*p)[i]);
            for(int j=i;j<(*len);j++){
                printf("hello\n");

                printf("%d\n",(*p)[j+1]);
                (*p)[j]=(*p)[j+1];
            }

        }
    }
}
int main(){
    int arr[]={12,4,54,10,43,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    int *ptr=arr;
    deleteelement(&ptr,&len,5);
    printf("\n");
    for(int i=0;i<len-1;i++){
        printf("%d\n",*ptr++);
    }

}