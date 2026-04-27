#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct array{
    char var;
    int count;
}array;

typedef struct node{
    int data;
    char var;
    struct node *left,*right;
}node;

typedef struct{
    node* root;
}Tree;

typedef struct {
    node arr[MAX];
    int size;
}MinHeap;

void initializetree(Tree *tree){
    tree->root=NULL;
}
void initializeHeap(MinHeap *minheap){
    minheap->size=0;
}
// void swap(node *node1,node *node2){
//     // printf("hello\n");
//     node *temp=node1;
//     node1=node2;
//     node2=temp;
// }

void Bottomup(MinHeap *minheap,int currentIndex){
    if(currentIndex<0){
        return;
    }
    int ParentIndex=(currentIndex-1)/2;
    if(minheap->arr[currentIndex].data<minheap->arr[ParentIndex].data){
        // swap(&minheap->arr[currentIndex],&minheap->arr[ParentIndex]);
        node temp=minheap->arr[currentIndex];
        minheap->arr[currentIndex]=minheap->arr[ParentIndex];
        minheap->arr[ParentIndex]=temp;
        Bottomup(minheap,ParentIndex);
    }

}
void topdown(MinHeap *minheap,int currentIndex){
    int parent=currentIndex;
    int leftchild=2*currentIndex+1;
    int rightchild=2*currentIndex+2;
    if(minheap->arr[parent].data>minheap->arr[leftchild].data && leftchild<minheap->size){
        parent=leftchild;   
    }
    if(minheap->arr[parent].data>minheap->arr[rightchild].data && rightchild < minheap->size){
        parent=rightchild;   
    }
    if(parent!=currentIndex){
        node temp=minheap->arr[currentIndex];
        minheap->arr[currentIndex]=minheap->arr[parent];
        minheap->arr[parent]=temp;
        topdown(minheap,parent);
    }

}
node  extractfromminimun(MinHeap *minheap){
    if(minheap->size<0){
        printf("Heap is Empty\n");
    }
    node *node1=minheap->arr[0];
    // printf("value %d  size %d\n",node1.data,minheap->size);

    minheap->size--;
    minheap->arr[0]=minheap->arr[minheap->size];
    topdown(minheap,0);
    return node1;
}

// typedef struct tree{
//     node* root;
// }structtree;

void Insert(MinHeap *minheap,node *node1){
    if(minheap->size==MAX){
        printf("capacity full\n");
        return;
    }
    minheap->arr[minheap->size]=node1;
    minheap->size++;
    Bottomup(minheap,minheap->size-1);
}
void display(MinHeap minheap){
 for(int i=0;i<minheap->size;i++){
    printf("%c %d\n",minheap->arr[i].var,minheap->arr[i].data);
 }
}
// void initializetree(structtree *tree){
//     tree->root=NULL;
// }
void extractelements(array *freqarray,int size,MinHeap *minheap){
    for(int i=0;i<size;i++){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=freqarray[i].count;
        newnode->var=freqarray[i].var;
        newnode->left=NULL;
        newnode->right=NULL;
        // node newnode;
        // newnode.var=freqarray[i].var;
        // newnode.data=freqarray[i].count;
        // newnode.left=NULL;
        // newnode.right=NULL;
        Insert(minheap,newnode);
    }
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
// int partition(array freqarray[],int low,int high){
//     int count;
//     char var;
//     int i=low+1;
//     int j=high;
//     int pivot=freqarray[low].count;
//     do{
//         while(pivot>=freqarray[i].count){
//             i++;
//         }
//         while(pivot<freqarray[j].count){
//             j++;
//         }
//         if(i<j){
//             // swap(&freqarray[i],&freqarray[j])
//             count=freqarray[i].count;
//             var=freqarray[i].var;
//             freqarray[i].count=freqarray[j].count;
//             freqarray[i].var=freqarray[j].var;
//             freqarray[j].count=count;
//             freqarray[j].var=var;
//         }
//     }while(i<j);
//     // swap(&freqarray[j],&freqarray[low]);
//     count=freqarray[i].count;
//     var=freqarray[i].var;
//     freqarray[i].count=freqarray[j].count;
//     freqarray[i].var=freqarray[j].var;
//     freqarray[j].count=count;
//     freqarray[j].var=var;
//     return j;
    
// }
// void sort(array freqarray[],int low,int high){
//     int partitionindex;
//     if(low<high){
//         partitionindex=partition(freqarray,low,high);
//         sort(freqarray,low,partitionindex-1);
//         sort(freqarray,partitionindex+1,high);
//     }
// }
// void createtree(array *freqarray,structtree *tree,int len){
//     int i=0;
//     // while(i<len){
//     //     if(tree->root==NULL){
//             node* node1=(node*)malloc(sizeof(node));
//             node1->data=freqarray[i].count;
//             node1->var=freqarray[i].var;
//             node1->left=NULL;
//             node1->right=NULL;
//             i++;
//             node* node2=(node*)malloc(sizeof(node));
//             node2->data=freqarray[i].count;
//             node2->var=freqarray[i].var;
//             node2->left=NULL;
//             node2->right=NULL;
//             i++;
//             node* parent1=(node*)malloc(sizeof(node));
//             parent1->data=node1->data+node2->data;
//             // strcpy(parent1->var,NULL);
//             parent1->left=node1;
//             parent1->right=node2;
//             tree->root=parent1;
    //     }

    // }
// }

// void display(structtree *tree){
//     node* temp=tree->root;
//     printf("%d ",temp->data);

// }
void createtree(Tree *tree,MinHeap *minheap){
    // while(minheap->size!=0){
        node *node1=extractfromminimun(minheap);
        node *node2=extractfromminimun(minheap);
        node *root=tree->root;
        node *newnode;
        newnode->data=node1.data+node2.data;
        newnode->var='X';
        newnode->left=node1; 
        newnode->right=node2;
        Insert(minheap,newnode);
        printf("%d\n",newnode->data);
        display(minheap);
        
    // }
}
int main(){
    char *inputstring;
    int length;
    array *freqarray=NULL;
    MinHeap minheap;
    Tree tree;
    // tree=(tree*)malloc(sizeof(tree));
    initializetree(&tree);
    // minheap=(MinHeap*)malloc(sizeof(MinHeap));
    initializeHeap(&minheap);
    printf("Enter the length of the string\n");
    scanf("%d",&length);
    inputstring=(char*)malloc(length*sizeof(char));
    printf("enter the string\n");
    scanf("%s",inputstring);
    freqarray=(array*)calloc(length,sizeof(array));
    int len=countfrequency(inputstring,length,freqarray);
    // printf("%d\n",len);
    for(int i=0;i<len;i++){
        printf("%c %d\n",freqarray[i].var,freqarray[i].count);
    }
    printf("\n\n");
    extractelements(freqarray,len,minheap);

    // sort(freqarray,len);
    // printf("\nafter sorting\n");
    // for(int i=0;i<len;i++){
    //     printf("%c %d\n",freqarray[i].var,freqarray[i].count);
    // }
    // structtree tree;
    // initializetree(&tree);
    // createtree(freqarray,&tree,len);
    // display(&tree);
    display(minheap);

    // node node1=extractminimun(minheap);
    // printf("data : %d var: %c\n",node1.data,node1.var);
    // node1=extractminimun(minheap);
    // printf("data : %d var: %c\n",node1.data,node1.var);
    // node1=extractminimun(minheap);
    // printf("data : %d var: %c\n",node1.data,node1.var);
    // node1=extractminimun(minheap);
    // printf("data : %d var: %c\n",node1.data,node1.var);
    // node1=extractminimun(minheap);
    // printf("data : %d var: %c\n",node1.data,node1.var);
    // createtree(&tree,minheap);
    return 0;


}