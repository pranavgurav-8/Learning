#include<stdio.h>
int main(){
    int n;
    printf("enter number:\n");
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        for(int j=i;j<n-i;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
        
    }
    // for(int i=1;i<=n;i++){
    //     printf("*");
    // }
    // printf("\n");
    for(int i=1;i<=n/2;i++){
        for(int j=i;j<=n/2;j++){
            printf("*");
        }
        for(int j=2;j<=2*i-1;j++){
            printf(" ");
        }
        for(int j=i;j<=n/2;j++){
            printf("*");
        }
        printf("\n");
        
    }
}

#include <stdio.h>


int main() {
    int rows = 5; // Number of rows in the pattern

    // Outer loop for each row
    for (int i = 1; i <= rows; i++) {
        // Inner loop for printing spaces
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Inner loop for printing asterisks
        for (int k = 1; k <= (2 * i) - 1; k++) {
            printf("*");
        }

        printf("\n"); // Move to the next line after each row is printed
    }

    return 0;
}
