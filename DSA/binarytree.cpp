#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:                 
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

static int index = -1;
Node* buildTree(const std::vector<int>& arr) {
    // Placeholder for tree building logic
    index++;
    if (index >= arr.size() || arr[index] == -1) {
        return nullptr;
    }
    Node *newNode = new Node(arr[index]);
    newNode->left = buildTree(arr);
    newNode->right =  buildTree(arr);
    return newNode;
}

void preOrderTraversal(Node* root) {
    if(root ==nullptr){
        return;
    }
    std::cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if(root ==nullptr){
        return;
    }
    inOrderTraversal(root->left);
    std::cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root ==nullptr){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout<<root->data<<" ";
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr == nullptr){
            if(!q.empty()){
                std::cout<<std::endl;
                q.push(nullptr);
                continue;
            }
            else{
                break;
            }
        }

        std::cout<<curr->data<<" ";
        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
    }
}

int main() {
    // Example usage:
    vector<int> arr = {1, 2, -1, -1, 3, 4,-1,-1, 5,-1,-1};
    Node* root = buildTree(arr);
    std::cout<<root->data<<std::endl;   
    preOrderTraversal(root);

    levelOrderTraversal(root);

    return 0;
}