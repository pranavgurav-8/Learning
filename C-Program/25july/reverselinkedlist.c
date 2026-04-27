#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct Linkedlist{
    node *head;
}LinkedList;

void initialize(LinkedList *list){
    list->head==NULL;
}
node *create_node(int val){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=NULL;
    return new_node;
}
void insertnode(LinkedList *list,int val){
    node *new_node=create_node(val); 
    if(list->head==NULL){
        list->head=new_node;
    }
    else{
        node* current=list->head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=new_node;
    }
}
void display(LinkedList *list){
    node * curr=list->head;
    while (curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr=curr->next;
    }
    
}
void reverse(LinkedList *list){
    node *prev=NULL;
    node *current=list->head;
    node* next=current->next;
    while (current!=NULL && next!=NULL){
        current->next=prev;
        prev=current;
        current=next;
        next=current->next;
    }
    current->next=prev;
    prev=current;
    list->head=prev;
    

}

int main(){
int val;
char value[20];
LinkedList list;
initialize(&list);
printf("enter ther elements to be stored in a linked list:");
scanf("%s",value);
char *token=strtok(value,",");
while(token!=NULL)
{   
    int val=atoi(token);
    insertnode(&list,val);
    token=strtok(NULL,",");
}
display(&list);
reverse(&list);
display(&list);


}