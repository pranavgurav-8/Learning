#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSTRING 4
#define MAXLENGTH 100
int main(int argc,const char *argv){
    int i;
    char **str;//array of pointers to strings 
    str=(char **)malloc(MAXSTRING*sizeof(char*));
    if(str==NULL){
        printf("Memory Allocation failed\n");
        return 1;
    }
    //allocate memory and read strings
    for(int i=0;i<MAXSTRING;i++){
        char buffer[MAXLENGTH];
        printf("Enter string\n");
        scanf("%s",buffer);

        //allocate memory for current string
        str[i]=(char *)malloc((strlen(buffer)+1)*sizeof(char));

        if(str[i]==NULL){
            printf("Memory allocation failed\n");
            return 1;
        }
        strcpy(str[i],buffer);
    }
    // Display the strings
    printf("Entered strings:\n");
    for(i=0;i<MAXSTRING;i++){
        printf("String[%d] is %s\n",i+1,str[i]);
    }

    // deallocate memory
    for(i=0;i<MAXSTRING;i++){
        free(str[i]);
    }
    free(str);
    return 0;
}

