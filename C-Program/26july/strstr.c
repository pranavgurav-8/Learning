#include<stdio.h>
#include<string.h>
int main(){
    char name[]="Pranav Gurav";
    char surname[]="Gurav";
    char *p;
    p=strstr(name,surname);
    if(p){
        printf("String %s found in %s is %s",surname,name,p);
        strcpy(p,"Mohan");
    }
    printf("\n%s\n",name);
}