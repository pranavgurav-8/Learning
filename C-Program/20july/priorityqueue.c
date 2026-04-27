#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int priority;
    struct node *next;
}node;
typedef struct queue{
    node *head;
    // node* tail;
}Queue;
void initialize(Queue *queue){
    queue->head=NULL;
    // queue->tail=NULL;
}
void display(Queue *queue){
    node *cur=queue->head;
    while(cur!=NULL){
        printf("value %d and priority %d\n",cur->data,cur->priority);
        cur=cur->next;
    }
}
int isEmpty(Queue *queue){
    return queue->head==NULL;
}
node *createnode(int val,int priority){
    node* new_node=(node *)malloc(sizeof(node));
    new_node->data=val;
    new_node->priority=priority;
    new_node->next=NULL;
    return new_node;
}
void insert(Queue *queue,int value,int priority){
    node* new_node=createnode(value,priority);
    if(isEmpty(queue) || queue->head->priority<priority){
        new_node->next=queue->head;
        queue->head=new_node;
        // queue->head=new_node;
        // queue->tail=new_node;
        return;
    }
    else{
        node *temp=queue->head;
        while(temp->next!=NULL && temp->next->priority>priority){
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }

// this code is for highest priority will be given to lowest number example is priority 1 will have highest priority.
    // node *temp=queue->head;
    // node *new_node=createnode(value,priority);
    // if(temp->priority>new_node->priority){
    //     new_node->next=temp;
    //     queue->head=new_node;
    //     return;
    // }
    // while(temp->next!=NULL){
    //     if(temp->priority<new_node->priority && temp->next->priority>new_node->priority){
    //         new_node->next=temp->next;
    //         temp->next=new_node; 
    //         return;    
    //     }
    //     temp=temp->next;
    // }
    // if(new_node->priority>queue->tail->priority){
    //     queue->tail->next=new_node;
    //     queue->tail=new_node;
    //     return;
    // }
    


    
    // queue->tail->next=new_node;
    // queue->tail=new_node;

}

int main(){
    int a,p,n=5;
    Queue queue;
    initialize(&queue);
    while(n-->0){
        printf("Enter the value and the priority: ");
        scanf("%d %d",&a,&p); 
        insert(&queue,a,p); 
    }
    display(&queue);
    


}















// #include <stdio.h>
// #include <stdlib.h>

// // Structure to represent an element in the priority queue
// typedef struct Node {
//     int data;
//     int priority;
//     struct Node* next;
// } Node;

// // Structure to represent the priority queue
// typedef struct {
//     Node* front;
// } PriorityQueue;

// // Function to create a new node
// Node* createNode(int data, int priority) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (newNode) {
//         newNode->data = data;
//         newNode->priority = priority;
//         newNode->next = NULL;
//     }
//     return newNode;
// }

// // Function to initialize the priority queue
// void initPriorityQueue(PriorityQueue* pq) {
//     pq->front = NULL;
// }

// // Function to insert an element into the priority queue
// void insert(PriorityQueue* pq, int data, int priority) {
//     Node* newNode = createNode(data, priority);

//     if (pq->front == NULL || priority > pq->front->priority) {
//         newNode->next = pq->front;
//         pq->front = newNode;
//     } else {
//         Node* temp = pq->front;
//         while (temp->next != NULL && temp->next->priority >= priority) {
//             temp = temp->next;
//         }
//         newNode->next = temp->next;
//         temp->next = newNode;
//     }
// }

// Function to extract the element with the highest priority from the priority queue
// int extractMax(PriorityQueue* pq) {
//     if (pq->front == NULL) {
//         printf("Priority Queue is empty\n");
//         return -1; // Assuming all elements are positive
//     }

//     Node* temp = pq->front;
//     int maxElement = temp->data;
//     pq->front = temp->next;
//     free(temp);
//     return maxElement;
// }

// int main() {
//     PriorityQueue pq;
//     initPriorityQueue(&pq);

//     insert(&pq, 20, 2);
//     insert(&pq, 10, 1);
//     insert(&pq, 30, 3);
//     insert(&pq, 40, 4);
//     insert(&pq, 5, 0);

//     printf("Extracted max element: %d\n", extractMax(&pq)); // Output: 40
//     printf("Extracted max element: %d\n", extractMax(&pq)); // Output: 30
//     printf("Extracted max element: %d\n", extractMax(&pq)); // Output: 40
//     printf("Extracted max element: %d\n", extractMax(&pq));
//     printf("Extracted max element: %d\n", extractMax(&pq)); // Output: 40

//     return 0;
// }
