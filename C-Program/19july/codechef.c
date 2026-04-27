// // no of plates
// #include <stdio.h>
// int main(void) {
// 	// your code goes here
// 	int X,Y,R,plates,testcase;
// 	scanf("%d",&testcase);
// 	while(testcase-->0){
// 	    scanf("%d %d %d",&X,&Y,&R);
// 	    int extra=R/30;
// 	    int sticks=X+extra;
// 	    plates=sticks/Y;
// 	    int extraplate=sticks%Y;
// 	    if(extraplate!=0){
// 	        plates++;
// 	    }
// 	    printf("%d\n",plates);
	    
// 	}
// 	return 0;
// }





#include <stdio.h>

int main()
{
    int n,i,j;
    printf("Enter n:");
    scanf("%d",&n);

    for(i=0;i<=n/2;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i>=j) || (i+j)>=n-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    for(i=(n/2)+1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((j<n/2) && (i+j<n))
                printf("*");
            else if((j>n/2) && (i<=j))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}