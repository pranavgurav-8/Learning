#include <iostream>

void reverseString(char *str){
    int left = 0;
    int right = 0;
    while(str[right] != '\0'){
        std::cout<<str[right]<<std::endl;
        right++;
    }
    std::cout<<right<<std::endl;
    right--;
    while(left < right){
        char swap = str[left];
        str[left] = str[right];
        str[right] = swap;
        
        right--;
        left++;
    }
}
int main(){
    char str[] = "hello";
    std::cout<<str<<std::endl;
    reverseString(str);
    
    std::cout<<str<<std::endl;
    
    return 0;
}