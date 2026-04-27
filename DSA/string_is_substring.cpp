// Online C++ compiler to run C++ program online
#include <iostream>
bool isSubString(std::string& s1, std::string& s2){
    return s1.find(s2) != std::string::npos;
}
int main() {
    std::string s1 = "Hello World";
    std::string s2 = "sd";
    
    std::cout<<isSubString(s1,s2)<<std::endl;
    return 0;
}

// Second approach


// Online C++ compiler to run C++ program online
#include <iostream>
bool isSubString(std::string& s1, std::string& s2){
    int length_s1 = s1.length();
    int length_s2 = s2.length();
    if(length_s2 > length_s1){
        return false;
    }
    for(int i = 0; i <= length_s1 - length_s2; i++){
        int j = 0;
        while(j<length_s2 && s1[i+j] == s2[j]){
            j++;
        }
        if(j==length_s2){
            return true;
        }
    }
    return false;
    
}
int main() {
    std::string s1 = "Hello World";
    std::string s2 = "Hello Worlds";
    
    std::cout<<isSubString(s1,s2)<<std::endl;
    return 0;
}