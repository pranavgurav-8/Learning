//To find if a substring is present in a string.
#include<stdio.h>
#include<string.h>
void checksubstring(char *text,char *pattern){

    
    int l1=strlen(text);
    int l2=strlen(pattern);
    for(int i=0;i<=l1-l2;i++){
        int j;
        for(j=0;j<l2;j++){
            if(text[i+j]!=pattern[j]){
                break;
            }
            // printf("%d\n",j);
        }
        if(j==l2){
            printf("Pattern found at index %d",i);
        }
        // printf("%d\n",i);
        
    }
}
int main(){
    char *text="hello hello";
    char *pattern="hello";

    checksubstring(text,pattern);



}
