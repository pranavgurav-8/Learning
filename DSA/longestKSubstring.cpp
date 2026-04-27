class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low = 0;
        int res = INT_MIN;
        unordered_map<char,int> freq;
        
        for(int high = 0; high < s.size(); high++){
            freq[s[high]]++;
            while(freq.size() > k){
                freq[s[low]]--;
                if(freq[s[low]]==0){
                    freq.erase(s[low]);
                }
                low++;
            }
            if(freq.size() == k){
                int len = high - low + 1;
                res = max(res,len);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};

