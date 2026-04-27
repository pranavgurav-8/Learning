#include<stdio.h>
int main(){
    int arr[]={5,-4,6,-3,4,-1};
    // int arr[]={7,69,2,221,8974};
    int size=sizeof(arr)/sizeof(arr[0]);
    int maxsum=0;
    int cursum=0;
    for(int i=0;i<size;i++){
        cursum+=arr[i];
        if(maxsum<cursum){
            maxsum=cursum;
        }
        if(cursum<0){
            cursum=0;
        }
    }
    printf("%d\n",maxsum);
       
}