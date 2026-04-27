// input ppp
// output pOp

// string stored in heap segment using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const* argv[]){
    int size=4;
    char *str=(char *)malloc(size*sizeof(char));
    printf("Enter:");
    scanf("%s",str);
    printf("string : %s\n",str);
    *(str+1)='O';
    printf("after modification of string : %s",str);
    return 0;
}