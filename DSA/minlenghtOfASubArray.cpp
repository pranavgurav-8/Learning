// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int res = INT_MAX;
        while(high < nums.size()){
            sum = sum + nums[high];
            while(sum >= target){
                int len = (high - low) + 1;
                res = min(res,len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        return res;
    }
};
int main() {
    // Write C++ code here
    vector<int> arr = {1,4,4};
    Solution s;
    cout<<s.minSubArrayLen(4, arr)<<endl;

    return 0;
}