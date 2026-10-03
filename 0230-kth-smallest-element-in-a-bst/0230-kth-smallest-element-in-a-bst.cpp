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
    int order=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;
        }
        if(root->left!=NULL){
            int leftVal=kthSmallest(root->left,k);
            if(leftVal!=-1){
                return leftVal;
            }
        }
        if(order+1==k){
            return root->val;
        }
        order=order+1;
        if(root->right!=NULL){
            int rightVal=kthSmallest(root->right,k);
            if(rightVal!=-1){
                return rightVal;
            }

        }
        return -1;
        
    }
};