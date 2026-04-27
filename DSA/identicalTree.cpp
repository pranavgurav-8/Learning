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

bool isIdentical(Node* root1, Node* root2){
    if(root1==nullptr || root2==nullptr){
        return root1==root2;
    }
    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    return (root1->data==root2->data) && left && right;
}

int main()
{
    vector<int> arr1 = {1,2,3};
    Node* root1 = buildTree(arr1);
    Node* root2 = buildTree(arr1); // Building identical tree

    return 0;
}
