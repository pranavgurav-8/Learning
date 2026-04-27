#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct Node
{
   int data;
   struct Node *next; 
}node;
typedef struct Queue{
    node *head;
    node *tail;
}Queue;

void initialize(Queue *queue){
    queue->head=NULL;
    queue->tail=NULL;
}
node* createnode(int value){
    node *new_node=(node*)malloc(sizeof(node*));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
int isEmpty(Queue *queue){
    return queue->head==NULL;
}
void enqueue(Queue *queue,int val){
    // printf("%d\n",val);
    if(isEmpty(queue)){
        node *new_node=createnode(val);
        queue->head=new_node;
        queue->tail=new_node;
        return;
    }
    node* new_node=createnode(val);
    queue->tail->next=new_node;
    queue->tail=new_node;
    return;
}
void dequeue(Queue *queue){
    if(queue->head==NULL){
        printf("Queue is Empty\n");
    }
    printf("Element to be dequeued = %d\n",queue->head->data);
    node* cur=queue->head;
    queue->head=cur->next;
    free(cur);
}
void display(Queue *queue){
    node *cur=queue->head;
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return;
    }
    while(cur!=NULL){
        printf("value %d\n",cur->data);
        cur=cur->next;
    }
}
int main(){
    Queue queue;
    initialize(&queue);
    char input[MAX];
    printf("Enter the values to the queue:\n");
    scanf("%s",input);
    char *token=strtok(input,",");
    while(token!=NULL){
        enqueue(&queue,atoi(token));
        token=strtok(NULL,",");
    }

    dequeue(&queue);
    printf("\n\n");
    display(&queue);
    
}