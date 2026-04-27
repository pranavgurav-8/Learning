#include<stdio.h>
#include<string.h>

void reverse(char **p){
    int left=0;
    int right=strlen(*p)-1;
    while(left<right){
        char temp=(*p)[left];
        (*p)[left]=(*p)[right];
        (*p)[right]=temp;
        left++;
        right--;
    }
}
int main(){
    char name[]="Hello World";
    char *ptr;
    ptr=name;
    reverse(&ptr);
    printf("%s",name);
}