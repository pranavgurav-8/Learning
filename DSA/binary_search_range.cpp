// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

int first(std::vector<int>& arr,int n){
    int x = 30;
    int low = 0;
    int high = n-1;
    int res =-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] < x){
            low = mid + 1;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            res = mid;
            high = mid-1;
        }
    }
    return res;
}

int last(std::vector<int>& arr,int n){
    int x = 30;
    int low = 0;
    int high = n-1;
    int res =-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] < x){
            low = mid + 1;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            res = mid;
            low = mid+1;
        }
    }
    return res;
}
int main() {
    // Write C++ code here
    std::vector<int> nums = {5,10,30,30,30,30,40,50};
    std::cout<<last(nums,8)<<std::endl;
    return 0;
}