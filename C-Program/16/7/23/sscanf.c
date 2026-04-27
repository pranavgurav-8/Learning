#include<stdio.h>
int main(int argc, char const **argv){
    char *details;
    int age;
    char firstname[10];
    char lastname[10];
    printf("Enter details: ");
    scanf("%[^\n]s",details);
    printf("%s",details);
    // sscanf(details,"%s %s %d",firstname,lastname,&age);
    // printf("%s",firstname);
}