#include<stdio.h>
int main(int argc, char *const argv[]){
    FILE *ptr=fopen("abc.txt","r");
    if(ptr==NULL){
        printf("no such file\n");
    }
    char str[100];
    while(fscanf(ptr,"%*s %*s %s",str)==1){
        printf("%s\n",str);
        
        printf("%c\n",*(str+1));
    }
    }
