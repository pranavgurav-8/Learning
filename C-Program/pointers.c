#include <stdio.h>

int main(int argc,char const *argv[]){
    int a=76;
    int *ptr=&a;
    printf("The value of a is %d",*ptr);
    return 0;
}