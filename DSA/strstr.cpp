#include <iostream>
#include <cstring>

const char* strstr1(const char* s1, const char* s2){
    if (*s2 == '\0')
        return s1;
        
    for(const char* it = s1; *it != '\0'; it++){
        const char* n = it;
        const char* m = s2;
        while(*n != '\0' && *m != '\0' && *m == *n){
            m++;
            n++;
        }
        if(*m == '\0'){
            return it;
        }
    }
    return nullptr;
}


int main(){
    const char *s1 = "Pranav Gurav";
    const char *s2 = "Gurav";
    
    std::cout<<strstr1(s1,s2)<<std::endl;
    
}
