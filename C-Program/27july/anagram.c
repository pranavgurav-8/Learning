// #include<stdio.h>
// #include<string.h>
// #include<stdbool.h>

// bool anagram(char *string,char *string2){
//     int len1=strlen(string);
//     int len2=strlen(string2);
//     int charcount[256]={0};
//     if(len1!=len2){
//         printf("Not a anagram\n");
//     }
//     for(int i=0;i<len1;i++){
//         charcount[(int)string[i]]++;
//     }
//     for(int i=0;i<len2;i++){
//         charcount[(int)string[i]]--;
//     }
//     for(int i=0;i<256;i++){
//         if(charcount[i]!=0){
//             return 0;
//         }
//     }
//     return 1;
    
// }

// int main(){
//     char string[10]="hello";;
//     char string2[10]="lleho";
    
    
//     if(anagram(string,string2)){
//         printf("Its a anagram\n");
//     }
    
// }



#include<stdio.h>
#include<string.h>
int main(){
    char name[]="pranav";
    char inp[]="vnaaep";
    int str1[26]={0};
    int str2[26]={0};
    int i=0,j=0;

    // printf("%d",'p'-'a');
    while(name[i]!='\0'){
        str1[name[i]-'a']++;
        printf("%d\n",str1[name[i]-'a']);
        i++;
    }
    printf("\n\n");
    while(inp[j]!='\0'){
        str2[inp[j]-'a']++;
        printf("%d\n",str2[inp[j]-'a']);
        j++;
    }
    if(i==j){
        for(int k=0;k<j;k++){
            if(str1[k]!=str2[k]){
                printf("not a anagram\n");
                return 0;
            }
        }
        printf("its a anagram\n");
    }
    
    // char c=97;

    // printf("%c\n",c);
}