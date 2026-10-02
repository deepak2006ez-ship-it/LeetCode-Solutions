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
    bool helper(TreeNode*root,TreeNode*minVal,TreeNode*maxVal){
        if(root==NULL){
            return true;
        }
        if(minVal!=NULL && minVal->val>=root->val){
            return false;
        }
        if(maxVal!=NULL && maxVal->val<=root->val){
            return false;
        }
        return helper(root->left,minVal,root) && helper(root->right,root,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
        
    }
};