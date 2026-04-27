// read and copy string using DMA
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *p,*s;
    int n;
    printf("Enter the size\n");
    scanf("%d",&n);
    p=(char *)malloc(n*sizeof(char));
    s=(char *)malloc(n*sizeof(char));
    printf("Enter a string:");
    scanf(" %s",p);
    printf("Entered value: %s",p);
    strcpy(s,p);
    printf("Entered value s: %s",s);

    free(p);
}