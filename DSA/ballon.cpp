#include <iostream>
#include <unordered_map>
#include <limits>

int  numberOfRansomCreated(std::unordered_map<char,int>&need,std::unordered_map<char,int>&have){
    
    int res = INT_MAX;


    for(auto i: need){
        char ch = i.first;
        int freq1 = i.second;
        int freq2 = have[ch];
        int times = freq2/freq1;

        res = std::min(times,res);
    }
    
    return true;
}
int main(){
    std::string magazine = "bbaallllooooonnn";

    std::unordered_map<char,int> need;
    std::unordered_map<char,int> have;

    need['b'] = 1 ;
    need['a'] = 1 ;
    need['l'] = 2 ;
    need['o'] = 2 ;
    need['n'] = 1 ;


    for(int i = 0; i < magazine.size(); i++){
        have[magazine[i]]++;
    }


    std::cout << numberOfRansomCreated(need,have)<<std::endl;
    return 0;

}