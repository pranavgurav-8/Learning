#include<stdio.h>
typedef struct petrolpump{
    int petrol;
    int distance;
}petrol;
int printstart(petrol *arr,int size){
    int start=0;
    int end=1;
    int cur_petrol=arr[start].petrol-arr[start].distance;
    while(end!=start || cur_petrol<0){
        while(cur_petrol<0 && start!=end){
            // printf("before current value is %d",cur_petrol);
            // printf("\ndiff %d\n",arr[start].petrol-arr[start].distance);
            cur_petrol-=arr[start].petrol-arr[start].distance;
            // printf("cur value %d and start is %d end is %d",cur_petrol,start,end);
            start=(start+1)%size;
            if(start==0){
                return -1;
            }
        }
        cur_petrol+=arr[end].petrol-arr[end].distance;
        end=(end+1)%size;     
    }
    return start;
}
int main(){
    petrol arr[]={{4,6},{6,5},{7,3},{4,5}};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("size %d\n",size);
    int index=printstart(arr,size);
    // for(int i=0;i<size;i++){
    //     printf("%d %d\n",arr[i].petrol,arr[i].distance);
    // }
    printf("\nstart positon %d,%d",arr[index].petrol,arr[index].distance);
}

