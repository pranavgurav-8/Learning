#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct stack
{
    int value[MAX];
    int top;
}stack;

void push(int val){
    if(stack.top==MAX-1){
        printf("Stack Overflow");
        return;
    }
    stack.top++;
    printf("push top %d value %d\n",stack.top,val);
    stack.value[stack.top]=val;
}

int pop(){
    if(stack.top==-1){
        printf("stack underflow\n");
        return -1;
    }
    return stack.value[stack.top--];
}
int peek(){
    if(stack.top==-1){
        printf("stack underflow\n");
        return -1;
    }
    return stack.value[stack.top];
    
}


int main(int argc, const char* argv[])
{
    int num;
    char elem[MAX];
    stack.top=-1;
    printf("Enter the element to be stored in the stack:\n");
    scanf("%[^\n]s",elem);
    char *token=strtok(elem," {},");
    while (token!=NULL)
    {
        int num=atoi(token);
        
        push(num);
        token=strtok(NULL," {},");
        /* code */
    }    
    printf("The element popped is %d\n",pop());
    printf("element peek: %d\n",peek());
    
}
