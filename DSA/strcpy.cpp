#include<iostream>

void strcopy(char *dest, const char *src){
    while(*src){
        *dest = *src;

        *dest++;
        *src++;
    }
}

int main(){
    char dest[];
    char name[] = "pranav";
    strcopy(dest,name);

    std::cout<<dest<<std::endl;
    return 0;
}