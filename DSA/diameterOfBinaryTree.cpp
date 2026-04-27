/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int heightOfBinaryTree(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftHt = heightOfBinaryTree(root->left);
        int rightHt = heightOfBinaryTree(root->right);

        ans = max(ans,leftHt+rightHt);

        return max(leftHt,rightHt)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==nullptr){
        //     return 0;
        // }
        // int leftDiameter = diameterOfBinaryTree(root->left);
        // int rightDiameter = diameterOfBinaryTree(root->right);
        // int currDiameter = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);

        // return max(currDiameter,max(leftDiameter,rightDiameter));

        heightOfBinaryTree(root);
        return ans;
    }
};