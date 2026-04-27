#include<stdio.h>
#include<stdlib.h>




void waiter(int q) {
//     // printf("%d ",number_count);
    int arr[]={1,2,3,50,1,4,2,10};
    int max=arr[0];
    for(int i=1;i<8;i++){
      if(max<arr[i]){
        max=arr[i];
      } 
    }
    printf("%d\n",max);
    
    int *prime=(int*)malloc((max+1)*sizeof(int));
    int count=0;
    int flag;
    int p=0;
    for(int i=2;i<=max;i++){
    flag=1;
    for(int j=2;j<i;j++){
        // if(i==j){
        //     break;
        // }
        if(i%j==0){
            flag=0;
        }
   } 
   if(flag){
    count++;
    printf("i %d\n\n",i);
    prime[p++]=i;
   }

}

for(int i=0;i<count;i++){
    printf("%d\n",prime[i]);
}
//     // int prime[]={2,3,5,6,7,11,13,17};

}
int main(){
    waiter(10);
//    int n=100;
//    int arr[10];
//    int k=0;
//    int flag;
//    for(int i=2;i<=n;i++){
//     flag=1;
//     for(int j=2;j<n/2;j++){
//         if(i==j){
//             break;
//         }
//         if(i%j==0){
//             flag=0;
//         }
//    } 
//    if(flag){
//     arr[k++]=i;
//    }

// }
// for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//     printf("%d\n",arr[i]);
// }
   

}