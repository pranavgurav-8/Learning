//input - Pranav Gurav 69
Output - 69
#include<stdio.h>
int main(int argc, char const * argv[]){
    int a;
    // to ignore the input until the next space or newline.
    // the below code reads only the integer
    printf("Enter:");
    scanf("%*s %*s %d",&a);
    printf("Input read is %d\n",a);
}