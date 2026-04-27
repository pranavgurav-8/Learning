#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *createnode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}
int search(node *root,int val){
    if(root==NULL){
        return 0;
    }
    if(root->data==val){
        return 1;
    }
    if(root->data>=val){
        search(root->left,val);
    }
    else{
        search(root->right,val);
    }
}
node * insert(node *root,int data){
    
    if(root==NULL){
        node *newnode=createnode(data);
        root=newnode;
        return root;
    }
    if(root->data>=data){
        // printf("Insert function left is called\n");
        root->left=insert(root->left,data);
        // printf("insert completed\n");
    }
    else{
       
        // printf("Insert function right is called\n");
        root->right=insert(root->right,data);
        // printf("insert right completed\n");
    }
    // printf("hello\n");
    // printf("%d %d\n",i,root->data);
    // printf("Root->left->data %d",root->left->data);
    return root;
}
void display(node *root){
    if(root==NULL){
       return; 
    }
    display(root->left);
        printf("%d",root->data);
        display(root->right);
}
int main(){
    node *root=NULL;
    int elem;
    for(int i=0;i<5;i++){
        printf("enter the data\n");
        scanf("%d",&elem);
        root=insert(root,elem);
    }
    // printf("%d",root->data);
    // printf("%d",root->right->data);

    display(root);
   if(search(root,32)){
    printf("\n\nElement found\n");
   }
   else{
    printf("not found\n");
   }

  

    
}

