#include<stdio.h>
#include<stdlib.h>
int binarysearch(int array[],int left,int right,int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(array[mid]==target){
            return 1;
        }
        if(array[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,3,31,45,49,56,78,98,222,300};
    int size=sizeof(arr)/sizeof(arr[0]);
    int index=binarysearch(arr,0,size-1,98);
    if(index==1){
        printf("Element found");
    }
    else{
        printf("Element not found\n");
    }
}