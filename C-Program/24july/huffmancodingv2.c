#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
typedef struct array{
    char var;
    int count;
}array;

typedef struct node{
    int data;
    char var;
    struct node* next;
}node;
typedef struct Queue{
    node *head;
    node *tail;
}Queue;

typedef struct Treenode{
    int data;
    char var;
    struct Treenode* left;
    struct Treenode *right;
}Treenode;
typedef struct Tree{
    Treenode *root;
}Tree;
void initialize(Queue *queue){
    queue->head=NULL;
    queue->tail=NULL;
}
void initializetree(Tree *tree){
    tree->root=NULL;
}
int countfrequency(char string[],int size,array freqarray[]){
    int *visited=(int*)calloc(size,sizeof(int));
    // int visited[10]={0};
    int ind=-1;
    for(int i=0;i<size;i++){
        if(visited[i]==0){
            // printf("%d\n")
            ind++; 
            freqarray[ind].var=string[i];
            freqarray[ind].count=1;
            for(int j=i+1;j<size;j++){
                if(string[j]==freqarray[ind].var){
                    freqarray[ind].count++;
                    visited[j]=1;
                }
            }
        }
       
    }
    return ind+1;
}

//dequeue function

node* dequeue(Queue *queue){
    if(queue->head==NULL){
        printf("Queue is Empty\n");
        return queue->head;
    }
    node *delnode;
    delnode=queue->head;
    queue->head=queue->head->next;
    return delnode;
}

void CreateTree(Queue *queue,Tree *tree){
    while(queue->head!=NULL){
    if(tree->root==NULL){
        // printf("tree is empty\n");
        node *qnode1=dequeue(queue);
        Treenode* tnode1=(Treenode*)malloc(sizeof(tnode1));
        tnode1->data=qnode1->data;
        tnode1->var=qnode1->var;
        tnode1->left=NULL;
        tnode1->right=NULL;
        // printf("element 1 %d %c\n",tnode1->data,tnode1->var);

        node *qnode2=dequeue(queue);
        Treenode* tnode2=(Treenode*)malloc(sizeof(tnode2));
        tnode2->data=qnode2->data;
        tnode2->var=qnode2->var;
        tnode2->left=NULL;
        tnode2->right=NULL;
        // printf("element 2 %d %c\n",tnode2->data,tnode2->var);

    Treenode *tnode=(Treenode*)malloc(sizeof(Treenode));
    tnode->data=tnode1->data+tnode2->data;
    tnode->var='\0';
    if(tnode->data>=tnode1->data){
        tnode->left=tnode1;
        tnode->right=tnode2;
    }
    else{
        tnode->left=tnode2;
        tnode->right=tnode1;
    }
    tree->root=tnode;
    // printf("parent %d %c",tnode->data,tnode->var);
    // printf("leftchild %d %c",tnode->left->data,tnode->left->var);
    // printf("rightchild %d %c",tnode->right->data,tnode->right->var);
}//end if root check
else{
    node *qnode1=dequeue(queue);
    // printf("hello\n in dequeue\n");
    // printf("values of new node %d\n",qnode1->data);
    // node *qnode2=dequeue(queue);
    if(qnode1!=NULL){
        Treenode* tnode1=(Treenode*)malloc(sizeof(tnode1));
        tnode1->data=qnode1->data;
        tnode1->var=qnode1->var;
        tnode1->left=NULL;
        tnode1->right=NULL;  
        Treenode *tnode=(Treenode *)malloc(sizeof(tnode));
        tnode->data=tnode1->data+tree->root->data;
        tnode->var='\0';
        if(tnode1->data>tnode->data && tnode1->data<tree->root->data){
            tnode->left=tnode1;
            tnode->right=tree->root;
            tree->root=tnode;
            // printf("root %d\n",tree->root->data);
            // printf("leftchild %d %c\n",tree->root->left->data,tree->root->left->var);
            // printf("righttchild %d %c\n",tree->root->right->data,tree->root->right->var);
        }
        else{
            tnode->right=tnode1;
            tnode->left=tree->root;
            tree->root=tnode;
            // printf("root %d\n",tree->root->data);
            // printf("leftchild %d %c\n",tree->root->left->data,tree->root->left->var);
            // printf("righttchild %d %c\n",tree->root->right->data,tree->root->right->var);

        }
    }

}
} 



}



void sort(array freqarray[],int len){
    int count;
    char var; 
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(freqarray[min].count>freqarray[j].count){
                min=j;
            }
        }
        count=freqarray[i].count;
        var=freqarray[i].var;
        freqarray[i].count=freqarray[min].count;
        freqarray[i].var=freqarray[min].var;
        freqarray[min].count=count;
        freqarray[min].var=var;
    }
}

void priorityqueue(Queue *queue,array arr[],int size){

    for(int i=0;i<size;i++){
        // node* newnode=createnode(arr,i);
        if(queue->head==NULL){
            node *newnode=(node*)malloc(sizeof(node));
            newnode->data=arr[i].count;
            newnode->var=arr[i].var;
            newnode->next=NULL;
            queue->head=newnode;
            queue->tail=newnode;
            // printf("head %d\n",newnode->data);
        }
        else{
            node *temp=queue->tail;
            node *newnode=(node*)malloc(sizeof(node));
            newnode->data=arr[i].count;
            newnode->var=arr[i].var;
            newnode->next=NULL;
            temp->next=newnode;
            queue->tail=newnode;
         }
    }
    }
void display(Queue *queue){
    node *temp=queue->head;
    int i=0;
    while(temp!=NULL){
        // printf("hello\n");
        i++;
        printf("%d %d %c\n",i,temp->data,temp->var);
        temp=temp->next;
    }
}

void decode(Tree *tree,char *str){
    Treenode *tnode=tree->root;
    char decodedstring[10];
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='1'){
            if(tnode->right->var!='\0'){
                printf("%c",tnode->right->var);
                tnode=tree->root;
               
            }
            else{
                tnode=tnode->right;
            }
        }
        else if(str[i]=='0'){
            if(tnode->left->var!='\0'){
                printf("%c",tnode->left->var);
                tnode=tree->root;
            }
                else{
                    tnode=tnode->left;
                    
                }
            }
        i++;
    }
        
    }


int main(){
    char *inputstring;
    int length;
    array *freqarray;
    char binary[20];
    Queue queue;
    Tree tree;
    initialize(&queue);
    initializetree(&tree);
    printf("Enter the length of the string\n");
    scanf("%d",&length);
    inputstring=(char*)malloc(length*sizeof(char));
    printf("enter the string\n");
    scanf("%s",inputstring);
    freqarray=(array*)calloc(length,sizeof(array));
    int len=countfrequency(inputstring,length,freqarray);
    printf("%d\n",len);
    for(int i=0;i<len;i++){
        printf("%c %d\n",freqarray[i].var,freqarray[i].count);
    }
    
    // priorityqueue(&queue,freqarray,len);
    // display(&queue);
    // printf("AFTER SORT\n");
    sort(freqarray,len);
    // for(int i=0;i<len;i++){
    //     printf("%c %d\n",freqarray[i].var,freqarray[i].count);
    // }
    printf("\n\n");
    priorityqueue(&queue,freqarray,len);
    // display(&queue);
    CreateTree(&queue,&tree);
    // CreateTree(&queue,&tree);
    printf("enter the string\n");
    scanf("%s",binary);
    // Tree *tnode=&tree;
    // printf("root %d\n",tnode->root->data);
    decode(&tree,binary);   
}