#include<iostream>
#include<unordered_map>

int getlongestPossiblePalindrome(std::string s){
    std::unordered_map<char,int> f;
    for(int i=0; i<s.size(); i++ ){
        f[s[i]]++;
    }

    bool odd = false;
    int res = 0;

    for(auto i: f){
        int val = i.second;
        if(val%2 == 0){
            res+=val;

        }
        else{
            odd = true;
            res+=val - 1;
        }
    }

    if(odd == true){
        res+=1;
    }
    return res;
}

int main(){
    std::string s = "aaabbb";
    std::cout<<getlongestPossiblePalindrome(s)<<std::endl;
}