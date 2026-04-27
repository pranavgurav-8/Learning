#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 5
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
    return ((queue->rear+1)%MAXSIZE==queue->front);
}
int isEmpty(Queue *queue){
    return queue->front==-1;
}
void enqueue(Queue *queue,int value){
    if(isFull(queue)){
        printf("Queue is full\n");
    }
    if(isEmpty(queue)){
        queue->front=0;
    }
    queue->rear=(queue->rear+1)%MAXSIZE;
    queue->array[queue->rear]=value;
}
void display(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
    }
    printf("Elemnets in the queue are:\n");
    if(queue->rear>=queue->front){
        for(int i=queue->front;i<=queue->rear;i++){
            printf("Elements %d\n",queue->array[i]);
        }
    }
    else{
        for(int i=queue->front;i<MAXSIZE;i++){
            printf("Elements %d\n",queue->array[i]);
        }
        for(int i=0;i<=queue->rear;i++){
            printf("Elements %d\n",queue->array[i]);
        }
    }
    printf("\n");
}
void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
    }
    printf("\n\n Element dequeued %d",queue->array[queue->front]);
    if(queue->rear==queue->front){
        queue->front=-1;
        queue->rear=-1;

    }
    else{
        queue->front=(queue->front+1)%MAXSIZE;
    }
    return;
    
}
int main(){
    Queue queue;
    initialize(&queue);
    char input[10];
    printf("Enter the queue elements:");
    scanf("%s",input);
    char *token=strtok(input,",");
    while(token!=NULL){
        enqueue(&queue,atoi(token));
        token=strtok(NULL,",");
    }
    display(&queue);
    dequeue(&queue);
    printf("\n\n");
    dequeue(&queue);
    printf("\n\n");
    display(&queue);
    enqueue(&queue,10);
    printf("\n\n");
    display(&queue);
}