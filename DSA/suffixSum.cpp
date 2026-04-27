

#include <iostream>
#include <vector>

std::vector<int> suffixSum(std::vector<int>& arr, int n){
    std::vector<int> suffixSumArray(n,0);
    for(int i=n-1; i>0; i--){
        suffixSumArray[i-1] = suffixSumArray[i]+arr[i];
    }
    return suffixSumArray;
}
int main()
{
    std::cout<<"Hello World\n";
    std::vector<int> arr = {1,2,3,4,5};

    std::vector<int> arr1 = suffixSum(arr,5);
        for(int i=0; i<5; i++){
            
        std::cout<<arr1[i] <<std::endl;
    }
    return 0;
}