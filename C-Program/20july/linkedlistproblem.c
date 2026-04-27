#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct Node {
    int data;
    struct Node *next;
}node;
typedef struct LinkedList{
    node *head;
}LinkedList;
void search(LinkedList *list,int val){
    node *cur=list->head;
    while(cur!=NULL){
        if(cur->data==val){
            printf("Element found %d",cur->data);
            return;
        }
        cur=cur->next;
    }
    printf("Element not found\n");
}
void initialize(LinkedList *list){
    list->head=NULL;
}
node *create_node(int val){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=NULL;
    return new_node;
}
void insertatbegining(LinkedList *list,int val){
    node *new_node=create_node(val);
    new_node->next=list->head;
    list->head=new_node;
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

void deleteatbegining(LinkedList *list){
    node *curr=list->head;
    list->head=curr->next;
    free(curr);
}
void deleteatend(LinkedList *list){
    node *prev=list->head;
    node *cur=prev->next;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
}
node* delete(node *temp){
    node* cur=temp;
    node* del=temp->next;
    cur->next=del->next;
    free(del);
    return cur;

}
void modify(LinkedList *list,int m,int n){
    node* temp=list->head;
    // node* prev;
    while(temp!=NULL){
        int i=1;
        int j=1;
        while(i<m && temp->next!=NULL){
            // prev=temp;
            temp=temp->next;
            i++;
        }
        while(j<=n && temp->next!=NULL){
            // prev=temp;
            temp=delete(temp);
            // temp=temp->next;
            j++;
        }
        temp=temp->next;
    }
}
int main(int argc,const char *argv){
    LinkedList list;
    initialize(&list);
    int elem,choice,m,n;
    char value[MAX];
    
    printf("enter ther elements to be stored in a linked list:");
    scanf("%s",value);
    char *token=strtok(value,",");
    while(token!=NULL)
    {   
        int val=atoi(token);
        insertnode(&list,val);
        token=strtok(NULL,",");
    }
    printf("Enter M and N ");
    scanf("%d %d",&m,&n);
    display(&list);
    modify(&list,m,n);
    printf("\n\n");
    display(&list);

}






