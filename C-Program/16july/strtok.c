#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv){
    char str[50];
    printf("Enter the string:");
    scanf("%[^\n]s",str);
    printf("%s\n\n",str);
    int values[10];
    int valuecount=0;
    char * token=strtok(str," ");
    while(token!=NULL){
        int value=atoi(token);
        printf("value %d\n",value);
        values[valuecount]=value;
        valuecount++;
        token=strtok(NULL," ");
    }
    for(int i=0; i<valuecount; i++){
        printf("%d\n",values[i]);
    }
}