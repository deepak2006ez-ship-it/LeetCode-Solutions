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
    int prevOrder=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;//here -1 indicate we havent found the ans so far
        }
        if(root->left!=NULL){
            int leftAns=kthSmallest(root->left,k);
            if(leftAns!=-1){
                return leftAns;
            }
        }
        if(prevOrder+1==k){
            return root->val;
        }
        prevOrder=prevOrder+1;
        if(root->right!=NULL){
            int rightAns=kthSmallest(root->right,k);
            if(rightAns!=-1){
                return rightAns;
            }
        }
        return -1;

    }
};