// Input={1,2,3,4,5,6,7,8,9}
// output:2,4,6,8,1,3,5,7,9
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    struct node *next;
};
struct node* createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

}
struct node* insertatend(struct node* head,int val){
    
    struct node* newnode=createnode(val);
    if(head==NULL){
        printf("%d\n",newnode->data);
        return newnode;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("%d\n",newnode->data);
    return head;
}

void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
 struct node *head=NULL;
 char input[20];
 int arr[10];
 printf("Enter the array:\n");
 scanf("%s",input);
 int i=0;
 char *token=strtok(input,"{},");
 while(token!=NULL){
    arr[i]=atoi(token);
    i++;
    token=strtok(NULL,"{,}");
 }
 
 for(int i=0;i<10;i++){
        int val=arr[i];
        if(val%2==0){
            insertatend(head,val);
        } 
}
for(int i=0;i<10;i++){
        int val=arr[i];
        if(val%2!=0){
            insertatend(head,val);
        } 
}
display(head);
 
}