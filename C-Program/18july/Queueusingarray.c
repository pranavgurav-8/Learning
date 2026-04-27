#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct Queueusingarray
{
    int array[MAXSIZE];
    int front;
    int rear;
}Queue;
void initialize(Queue * queue){
    queue->front=-1;
    queue->rear=-1;
}
int isFull(Queue *queue){
    return queue->rear==MAXSIZE-1;
}
int isEmpty(Queue *queue){
    return queue->front==-1;
}
void enqueue(Queue *queue,int val){
    if(isFull(queue)){
        printf("Queue is full\n");
        return;
    }
    if(isEmpty(queue)){
        queue->front=0;
    }
    queue->rear++;
    queue->array[queue->rear]=val;
}
void display(Queue* queue){
    if(isEmpty(queue)){
        printf("queue is Empty\n");
        return;
    }
    for(int i=queue->front;i<=queue->rear;i++){
        printf("element %d\n",queue->array[i]);
    }
}
void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    printf("Element is %d",queue->array[queue->front]);
    if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
    }
    else{
        queue->front++;
    }
    return;
}
int main(){
    Queue queue;
    char input[MAXSIZE];
    initialize(&queue);
    printf("Enter the queue elements:");
    scanf("%s",input);
    char *token=strtok(input,",");
    while(token!=NULL){
        enqueue(&queue,atoi(token));
        token=strtok(NULL,",");
    }
    display(&queue);
    dequeue(&queue);
    printf("\n\nAfter dequeue\n");
    display(&queue);
}