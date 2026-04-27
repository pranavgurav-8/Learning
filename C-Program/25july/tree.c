#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

typedef struct Tree{
    
    node *root;
}Tree;

void initialize(Tree **tree){
    *tree=(Tree*)malloc(sizeof(Tree));
    (*tree)->root=NULL;
}
node *createnode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void insert(node **root,int data){
    // node* root=tree->root;
    if(*root==NULL){
        // printf("helo\n");
        *root=createnode(data);
        // return *root;
        // return;
    }
    else if(data<=(*root)->data){
        insert(&(*root)->left,data);
        // printf("helohiiii\n");
    }
    else{
         insert(&(*root)->right,data);
    }
 

}

void display(node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main(){
    Tree *tree;
    initialize(&tree);
    insert(&tree->root,6);
    insert(&tree->root,5);
    display(tree->root);





}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAXSIZE 10

// typedef struct node {
//     int data;
//     struct node* left;
//     struct node* right;
// } node;

// typedef struct Tree {
//     node* root;
// } Tree;

// void initialize(Tree* tree) {
//     tree->root = NULL;
// }

// node* createnode(int val) {
//     node* newnode = (node*)malloc(sizeof(node));
//     newnode->data = val;
//     newnode->left = NULL;
//     newnode->right = NULL;
//     return newnode;
// }

// node* insert(node* root, int data) {
//     if (root == NULL) {
//         return createnode(data);
//     }
//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     } else {
//         root->right = insert(root->right, data);
//     }
//     return root; // Return the updated root after insertion
// }

// // Function to display the binary tree (inorder traversal)
// void display(node* root) {
//     if (root != NULL) {
//         display(root->left);
//         printf("%d ", root->data);
//         display(root->right);
//     }
// }

// // Function to destroy the binary tree and free memory
// void destroyTree(node* root) {
//     if (root != NULL) {
//         destroyTree(root->left);
//         destroyTree(root->right);
//         free(root);
//     }
// }

// int main() {
//     Tree tree;
//     initialize(&tree);

//     tree.root = insert(tree.root, 6);
//     tree.root = insert(tree.root, 5);
//     tree.root = insert(tree.root, 8);
//     tree.root = insert(tree.root, 3);
//     tree.root = insert(tree.root, 7);

//     printf("Inorder Traversal: ");
//     display(tree.root);
//     printf("\n");

//     destroyTree(tree.root);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data <= (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    destroyTree(root);

    return 0;
}
