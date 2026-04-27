#include<stdio.h>
#define MAX 20
 typedef struct  {
    char arr[MAX];
    int top;
}Stack;
void initialize(Stack *stack){
    stack->top=-1;
}
int isFULL(Stack *stack){
    if(stack->top==MAX-1){
        return 1;
    }
    return 0;
}
void push(Stack *stack,char val){
    if(isFULL(stack)){
        printf("stack Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top]=val;
    // printf("value at top %d is %c",stack->top,stack->arr[stack->top]);

}
int isEmpty(Stack *stack){
    if(stack->top==-1){
        return 1;
    }
    return 0;
}
void pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underlfow\n");
        return;
    }
    stack->top--;
}

int main(int argc,const char *argv){
    Stack stack;
    // stack.top=-1;
    initialize(&stack);
    int i=0;
    char input[MAX];
    printf("Enter the string:");
    scanf("%s",input);
    while(input[i]!='\0'){
        if(input[i]=='{' || input[i] =='(' || input[i] == '['){
            push(&stack,input[i]);
        }
        else if(input[i]=='}' || input[i] ==')' || input[i] == ']'){
            pop(&stack);
        }
        else{
            i++;
            continue;
        }
        i++;
    }
    if(stack.top==-1){
        printf("Balanced paranthesis");
    }
    else{
        printf("Paranthesis is not balanced\n");
    }
}