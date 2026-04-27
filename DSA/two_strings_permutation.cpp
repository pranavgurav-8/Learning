
// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

void checkPermutation(const char *s, const char *s2){
    int length = std::strlen(s);
    if(std::strlen(s)!=std::strlen(s2)){
        std::cout<<"Failed"<<std::endl;
        return;
    }
    int freqArray[26]={0};
    
    for(int i = 0; i< length; i++){
        int index = s[i] - 'a';
        index = index%26;
        freqArray[index]++;
    }
    for(int i = 0; i< length; i++){
        int index = s2[i] - 'a';
        index = index % 26;
        if(--freqArray[index] < 0){
            std::cout<<"Failed"<<std::endl;
            return;
        }
    }
    std::cout<<"Successful"<<std::endl;
    
}
int main() {
    // Write C++ code here
    const char *s = "pranavz";
    const char *s2 = "avanrp";
    
    checkPermutation(s,s2);

    return 0;
}