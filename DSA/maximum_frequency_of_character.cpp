#include <iostream>
#include <unordered_map>
char maxFrequencyCharacter(std::string& s){
    if(s.empty()){
        return '\0';
    }
    std::unordered_map<char,int> freq;
    int maxFreq = 0;
    char ch = s[0];
    for(int i = 0; i < s.length(); i++){
        int count = ++freq[s[i]];
        if(count > maxFreq){
            maxFreq = count;
            ch =s[i];
        }
    }
    return ch;
}
int main(){
    std::string str = "Prrranav";
    std::cout<<maxFrequencyCharacter(str)<<std::endl;
    
}
