#include<stdio.h>
void swap(int **p,int **q){
    int temp=**p;
    **p=**q;
    ** q=temp;

}
int main(){
    int a=5,b=10;
    int *ptr1=&a;
    int *ptr2=&b;
    swap(&ptr1,&ptr2);
    printf("%d %d\n",a,b);
}