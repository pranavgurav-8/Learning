#include<stdio.h>
int main(int argc, char **argv){
    char *name="Pranav Gurav";
    char *ptr=name;
    while(*ptr!='\0'){
        printf("%c\n",*ptr);
        // printf("Hello");
        ptr++;
    }
    return 0;

};
