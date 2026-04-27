#include<stdio.h>
#include<string.h>
int main(){
    // int n;
    // printf("Enter number\n");
    // scanf("%*s %d",&n);
    // printf("%d",n);
    for(int i=1;i<=5;i++){
        for(int j=i;j<5;j++){
            printf(" ");
        }
       for(int j=1;j<i;j++){
        printf("*");
       }
       for(int j=1;j<=i;j++){
        printf("*");
       }
       printf("\n");
    }
    for(int i=2;i<=5;i++){
        for(int j=1;j<i;j++){
            printf(" ");
        }
       for(int j=i;j<5;j++){
        printf("*");
       }
       for(int j=i;j<=5;j++){
        printf("*");
       }
       printf("\n");
    }
    
}