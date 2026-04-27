// Input {30,10,,20,50,40,50,60,30,10}
//Output - Count of distinct numbers is 6

#include<stdio.h>
#define MAX 10
int main(){
    int arr[]={30,10,,20,50,40,50,60,30,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    int visit[MAX]={0};
    for(int i=0;i<size;i++){
        if(visit[i]==0){
            for(int j=i+1;j<=size;j++){
                if(arr[i]==arr[j]){
                    visit[j]=1;
                }
            }
            count++;
        }
    }
    printf("Count of distinct numbers is %d",count);
}