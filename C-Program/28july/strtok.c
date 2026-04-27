#include<stdio.h>
#include<string.h>
int main(){
    char no[2],mon[4],year[5];
    char name[]="29 oct+2023";
    char *token=strtok(name," ");
    sscanf(token,"%s",no);
    printf("\n%s\n",no);

    token=strtok(NULL, "+");
    sscanf(token,"%s",mon);
    printf("\n%s\n",mon);

    token=strtok(NULL, " ");
    sscanf(token,"%s",year);
    printf("\n%s\n",year);
}