// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
int getMinimumValueIndex(std::vector<int>& arr){
    int n = arr.size();
    int low =0;
    int high = n - 1;
    int res;
    
    while(low<high){
        int mid = (low + high)/2;
        if(arr[mid]>arr[n-1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
            res = mid;
        }
    }
    return res;
}
int main() {
    std::vector<int> arr = {5,6,7,8,9,1,2,3,4};
    std::cout<<getMinimumValueIndex(arr)<<std::endl;
    return 0;
}