#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **names=(char**)malloc(5*sizeof(char*));
    for(int i=0;i<5;i++){
        names[i]=(char *)malloc(10*sizeof(char));
    }
    char shri[10];
    strcpy(shri,"Shrinath");
    names[0]=shri;
    // names[0]="Hello";
    names[1]="Pranav";
    names[2]="Gurav";
    names[3]="How";
    names[4]="are you";
    printf("Message %s %s %s %s %s\n",*names,*(names+1),*(names+2),*(names+3),*(names+4));
    // strcpy(*names,*(names+1));              error
    // assigning values of pointers
    // names[0]=names[1];     
    printf("Message %s %s %s %s %s\n",*names,*(names+1),*(names+2),*(names+3),*(names+4));

    for(int i=0;i<5;i++){
        for(int j=0;j<strlen(names[i]);j++){
            printf("%c \n",*(*(names+i)+j));
        }
        printf("\n");
    }
}