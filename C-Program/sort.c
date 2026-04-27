#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
    int arr[]={2,34,5,21,4,13,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
}