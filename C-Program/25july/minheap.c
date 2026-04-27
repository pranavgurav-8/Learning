#include<stdio.h>
#include<stdlib.h>
#define MAXCAPACITY 10
typedef struct MinHeap{
    int *arr;
    int size;
    int capacity;
}MinHeap;

void createminheap(MinHeap *heap,int capacity){
    heap->arr=(int*)malloc(capacity*sizeof(int));
    if(heap->arr==NULL){
        free(heap);
    }   
    heap->size=0;
    heap->capacity=capacity;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapifyUp(MinHeap *heap,int index){
    int parent=(index-1)/2;
    while(index>0 && heap->arr[parent]>heap->arr[index]){
        swap(&heap->arr[parent],&heap->arr[index]);
        index=parent;
        parent=(index-1)/2;
        heapifyUp(heap,index);
    }
    printf("parent %d\n",heap->arr[0]);
}
void insert(MinHeap *heap,int val){
    if(heap->size==heap->capacity){
        printf("Heap is Full\n");
        return;
    }
    heap->arr[heap->size]=val;
    heap->size++;
    heapifyUp(heap,heap->size-1);
}
void heapifyDown(MinHeap *heap,int val){
    int smallest=val;
    int leftchild=(2*smallest)+1;
    int rightchild=(2*smallest)+2;
    if(leftchild<heap->size && heap->arr[smallest]>heap->arr[leftchild]){
        smallest=leftchild;
    }
    if(rightchild<heap->size && heap->arr[smallest]>heap->arr[rightchild]){
        smallest=rightchild;
    }
    if(smallest!=val){
        swap(&heap->arr[smallest],&heap->arr[val]);
        heapifyDown(heap,smallest);
    }
}


int delete(MinHeap *heap){
    if(heap->size<0){
        printf("heap underflow\n");
        return -1;
    }
    int val=heap->arr[0];
    heap->arr[0]=heap->arr[heap->size--];
    // heap->size--;
    heapifyDown(heap,0);
    return val;
}
void display(MinHeap *heap){
    while (heap->size>0)
    {
        printf("%d ",delete(heap));
    }
    return;
}
int main(){
    int data;
    MinHeap *heap=malloc(sizeof(MinHeap));
    createminheap(heap,MAXCAPACITY);
    printf("Enter the elements to insert in a heap\n");
    for(int i=0;i<MAXCAPACITY;i++){
        printf("%d ",i);
        scanf("%d",&data);
        // insert(heap,data);
    }
    // display(heap);
    
}