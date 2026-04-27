#include<stdio.h>
int main()
{
    int arr1[3];
    int arr2[3];
    int arr3[3];
    int *arrayofpointers[]={arr1,arr2,arr3};
    int **ptr;
    ptr=arrayofpointers;
    // printf("Value is %d",**ptr);
    // **ptr++;
    // printf("Enter an elment: ");
    // scanf("%d",(*(ptr+0)+2));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter an elment: ");
            scanf("%d",(*(ptr+i)+j));
        }
    }
    for(int i=0;i<3;i++){
        // for(int j=0;j<3;j++){
            int j=0;
            printf("%d %d %d\n",*(*(ptr+i)+j),*(*(ptr+i)+j+1),*(*(ptr+i)+j+2));
            // scanf("%d",(*(ptr+i)+j));
        // }
    }
    // printf("Value is %d",*(*(ptr+0)+2));

}