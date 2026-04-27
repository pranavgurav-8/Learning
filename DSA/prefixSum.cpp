

#include <iostream>
#include <vector>

std::vector<int> prefixSum(std::vector<int>& arr, int n){
    std::vector<int> prefixSumArray(n,0);
    for(int i=1; i<n; i++){
        prefixSumArray[i] = prefixSumArray[i-1]+arr[i-1];
    }
    return prefixSumArray;
}
int main()
{
    std::cout<<"Hello World\n";
    std::vector<int> arr = {1,2,3,4,5};

    std::vector<int> arr1 = prefixSum(arr,5);
        for(int i=0; i<5; i++){
            
        std::cout<<arr1[i] <<std::endl;
    }
    return 0;
}