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
    int ans=INT_MAX;
    TreeNode*prev=NULL;
    void find(TreeNode*root){
        if(root==NULL){
            return ;
        }
        find(root->left);
        if(prev!=NULL){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        find(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        find(root);
        return ans;
        
    }
};