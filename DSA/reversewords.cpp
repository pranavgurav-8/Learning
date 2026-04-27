#include<iostream>
#include<algorithm>

void strReverse(std::string &str){
    
    reverse(str.begin(),str.end());
    int i = 0;
    int start = 0;
    
    for(int i = 0; i <= str.length(); i++){
        if(i == str.length() || str[i] == ' '){
            reverse(str.begin()+start, str.begin()+i);
            start = i+1;
    }    
    }

    
    std::cout<<str<<std::endl;

    
}

int main(){
    std::string name = "my name is pranav";
    strReverse(name);
    return 0;
}