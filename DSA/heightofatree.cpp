#include<iostream>
#include<vector>

using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }   
};

static int index=-1;

Node* buildTree(vector<int> arr){
    // Placeholder for tree building logic
    index++;
    if(arr[index]==-1 || index>=arr.size()){
        return nullptr;
    }
    Node* newNode=new Node(arr[index]);
    newNode->left=buildTree(arr);
    newNode->right=buildTree(arr);  
    return newNode;
}

int heightOfTree(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftheight = heightOfTree(root->left);
    int rightheight = heightOfTree(root->right);
    return max(leftheight,rightheight)+1;
}

int countNodes(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);
    return leftcount + rightcount + 1;
}
int sumOfNodes(Node* root)
{
    if(root==nullptr){
        return 0;
    }
    int leftsum = sumOfNodes(root->left);
    int rightsum = sumOfNodes(root->right);
    return leftsum + rightsum + root->data;
}
int main()
{
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(arr);
    std::cout<<heightOfTree(root)<<std::endl;

    std::cout<<countNodes(root)<<std::endl;

    std::cout<<sumOfNodes(root)<<std::endl;
    return 0;
    
}