/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }   
        if(root==p || root==q){
            return root;
        }
        TreeNode*leftLca=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightLca=lowestCommonAncestor(root->right,p,q);
        if(leftLca!=NULL && rightLca!=NULL){
            return root;
        }
        if(leftLca==NULL && rightLca!=NULL){
            return rightLca;
        }
        if(leftLca!=NULL && rightLca==NULL){
            return leftLca;
        }else{
            return NULL;
        }
    }
};