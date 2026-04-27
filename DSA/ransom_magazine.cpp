#include <iostream>
#include <unordered_map>


bool isHaveMoreThanNeed(std::unordered_map<char,int>&need,std::unordered_map<char,int>&have){
    
    for(auto i: need){
        char ch = i.first;
        int freq1 = i.second;
        int freq2 = have[ch];
        if(freq1>freq2){
            return false;
        }
    }
    
    return true;
}
int main(){
    std::string random = "AAB";
    std::string magazine = "ABA";

    std::unordered_map<char,int> need;
    std::unordered_map<char,int> have;

    for(int i = 0; i < random.size(); i++){
        need[random[i]]++;
    }

    for(int i = 0; i < magazine.size(); i++){
        have[magazine[i]]++;
    }


    std::cout << isHaveMoreThanNeed(need,have)<<std::endl;
    return 0;

}