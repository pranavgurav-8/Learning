#include<stdio.h>
#define MAX 50
int main(int argc, char **argv)
{
    char name[100];
    printf("Enter string:");
    // printf("%ld",sizeof(name));
    fgets(name,sizeof(name),stdin);
    printf("%s",name);

}