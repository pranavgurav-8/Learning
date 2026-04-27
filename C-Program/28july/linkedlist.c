#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct Linkedlist{
    node *head;
}Linkedlist;
void initialize(Linkedlist *list){
    list->head=NULL;
}

node *createnode(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void insert(Linkedlist *list,int val){
    if(list->head==NULL){
        list->head=createnode(val);
    }
    else{
        node* curr=list->head;
        node* newnode=createnode(val);
        while(curr->next!=NULL){
            curr=curr->next;
    }
    curr->next=newnode;
    }
    
}

void display(Linkedlist *list){
    node *curr=list->head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
int main(){
    Linkedlist list;
    initialize(&list);
    char input1[10];
    printf("enter string\n");
    scanf("{%[^}]%*c}",input1);
    char *token=strtok(input1,",");
    while(token!=NULL){
        insert(&list,atoi(token));
        token=strtok(NULL,",");
    }
    display(&list);
    
    
    

}

