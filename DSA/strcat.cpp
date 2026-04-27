#include <iostream>

char* strcat1(char* dest, const char* src){
    char *start = dest;
  while(*dest != '\0'){
      dest++;
  }
  
  while(*src != '\0'){
      *dest = *src;
      src++;
      dest++;
  }
  *dest ='\0';
  return start;
}


int main(){
    char dest[50] = "Pranav";
    char src[] = " Gurav";
    std::cout<<strcat1(dest,src)<<std::endl;
    
}
