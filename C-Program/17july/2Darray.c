#include<stdio.h>
#include<string.h>
#define MAXSTRING 5
#define MAXLENGTH 100
void display(char strings[][MAXLENGTH],int val){
    for(int i=0;i<val;i++){
        printf("%s\n",strings[i]);
    }      
}
void copyfunction(char destination[],char source[]){
    strcpy(destination,source);
}
int main(int argc,const char *argv){
    char str[MAXSTRING][MAXLENGTH];
    char copy[MAXLENGTH];
    for(int i=0;i<MAXSTRING;i++){
        printf("Enter the %d string\n",i+1);
        scanf("%s",str[i]);
    }
    copyfunction(copy,str[0]);  // printf("Entered strings\n");
    // for(int i=0;i<MAXSTRING;i++){
    //     printf("%s\n",str[i]);
    // } 
    // display(str,MAXSTRING);
    printf("copied string : %s",copy);
}
    
