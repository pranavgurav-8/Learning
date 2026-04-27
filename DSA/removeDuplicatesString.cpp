#include <iostream>

std::string removeDuplicate(std::string &name){
    bool seen[256] = {false};
    std::string result;
    
    for(char ch: name){
        if(!seen[(int)ch]){
            seen[(int)ch] = true;
            result.push_back(ch);
        }
    }
    return result;
}

int main(){
    std::string str = "programmer";
    std::cout<<removeDuplicate(str)<<std::endl;
    
    return 0;
}