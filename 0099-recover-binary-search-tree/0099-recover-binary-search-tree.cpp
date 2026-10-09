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
    TreeNode*prev=NULL;
    TreeNode*first=NULL;
    TreeNode*second=NULL;
    void inorderTraversal(TreeNode*root){
        if(root==NULL){
            return ;
        }
        inorderTraversal(root->left);
        if(prev!=NULL){
            if(prev->val>root->val){
                if(first==NULL){
                    first=prev;
                }
                second=root;
            }
        }
        prev=root;
        inorderTraversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};