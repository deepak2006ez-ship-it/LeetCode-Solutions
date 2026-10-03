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
        TreeNode*leftVal=NULL; 
    TreeNode*rightVal=NULL; 
        if(root->val>p->val || root->val>q->val){
            leftVal=lowestCommonAncestor(root->left,p,q);
        }
        if(root->val<p->val || root->val<q->val){
            rightVal=lowestCommonAncestor(root->right,p,q);
        }




        if(leftVal!=NULL && rightVal!=NULL){
            return root;
        }
        if(leftVal!=NULL &&rightVal==NULL ){
            return leftVal;
        }
        if(rightVal!=NULL && leftVal==NULL){
            return rightVal;
        }else{

            return NULL;
        }
    }
}
;