input : "MALAYALAM"
output : "MALY"

#include<iostream>
#include<unordered_set>

int main(){
    std::string str = "MALAYALAM";
    std::unordered_set<char> visited;
    std::string result;

    for(char c: str){
        if(visited.find(c)==visited.end()){
            result += c;
            visited.insert(c);
        }
    }
    
    std::cout<<result<<std::endl;
    return 0;

}