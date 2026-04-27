#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 20
typedef struct stack{
    char *arr;
    int top;
    int size;
}Stack;
void initializestack(Stack *stack,int size){
    stack->size=size;
    stack->arr=(char*)malloc(stack->size*sizeof(char));
    stack->top=-1;
}
void push(Stack *stack,char val){
    if(stack->top==stack->size-1){
        printf("Stack full\n");
        return;
    }
    // stack->top++;
    stack->arr[++stack->top]=val;
    // printf("%d\n",val);
    // printf("top %d %c\n",stack->top,stack->arr[stack->top]);

}
char pop(Stack *stack){
    // printf("HEllo\n");
    if(stack->top==-1){
        printf("Stack empty\n");
        return '\0';
    }
    char val=stack->arr[stack->top--];
    return val;
}
int isOperator(char c){
    if(c=='+' || c=='/' || c=='-' || c == '*'){
        return 1;
    }
    return 0;
}
int getprecedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
int main(){
    // int val,choice;
    char string[MAX];
    Stack *stack;
    stack=(Stack*)malloc(sizeof(Stack));
    initializestack(stack,MAX);
    printf("Enter the infix expression\n");
    scanf("%s",string);
    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '|| string[i]=='\t'){
            continue;
        }
        if(isalnum(string[i])){
            printf("%c",string[i]);
        }
        else if(string[i]=='('){
            push(stack,string[i]);
        }
        else if(string[i]==')'){
            while(stack->arr[stack->top]!='('){
                printf("%c",pop(stack));
            }
            stack->top--;
            
        }
        else if(isOperator(string[i])){
            if(getprecedence(string[i])>getprecedence(stack->arr[stack->top])){
                    // printf("i %d",i);
                    push(stack,string[i]);
            }
            else{
                // printf("i %d",i);
                while(stack->top >-1 && getprecedence(string[i])<=getprecedence(stack->arr[stack->top])){
                    printf("%c",pop(stack));
                }
                
                push(stack,string[i]);
            }
            
        }
    }
    
    while(stack->top!=-1){
        printf("%c",pop(stack));
    }
}
    // do{
    //     printf("enter your choice\n1.push\n2.pop\n");
    //     scanf("%d",&choice);
    //     switch(choice){
    //         case 1:
    //             printf("push\n");
    //             scanf("%d",&val);
    //             push(stack,val);
    //             break;
    //         case 2:
    //             printf("pop\n");
    //             pop(stack);
    //             break;
    //         default:
    //             exit(0);

    //     }
    // }while(1);
    
    // push(stack,5);
    // push(stack,4);
    // push(stack,3);
    // pop(stack);
    // pop(stack);pop(stack);pop(stack);
    // pop(stack);
// 
// }