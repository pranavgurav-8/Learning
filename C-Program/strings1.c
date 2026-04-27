#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    // to find the length and display the string
    // char str[]="Pranav";
    // int len=strlen(str);
    // printf("%s",str);
    // printf("\nLENGTH is %d\n\n",len);
    
    // take the input from the user
    char str[50];
    printf("Enter the string:");
    scanf("%[^\n]s",str);
    printf("%s",str);
    return 0;

    

}
