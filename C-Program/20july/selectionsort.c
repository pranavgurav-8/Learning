#include<stdio.h>
void swap(int *a,int *b){
    // printf("a is %d b is %d\n",*a,*b);
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
//     printf("after swaping\n");
//     printf("a is %d b is %d\n",*a,*b);
}
void selectionsort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}
int main(){
    int arr[]={2,3,41,4,12,13,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<size;i++){
    //     printf("array elements %d\n",arr[i]);
    // }
    printf("\n");
    selectionsort(arr,size);
    for(int i=0;i<size;i++){
        printf("array elements %d\n",arr[i]);
    }
    

}