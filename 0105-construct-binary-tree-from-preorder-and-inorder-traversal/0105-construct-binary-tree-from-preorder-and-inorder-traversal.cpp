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
    int inorderIdx(vector<int>&inorder,int left ,int right,int key){
        for(int i=left;i<=right;i++){
            if(inorder[i]==key){
                return i;
            }
        }
        return -1;
    }
    TreeNode*helper(vector<int>&preorder,vector<int>&inorder,int &i,int left,int right){
        if(i>=preorder.size()||left>right){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[i]);
        i++;
        int inIdx=inorderIdx(inorder,left,right,root->val);
        root->left=helper(preorder,inorder,i,left,inIdx-1);
        root->right=helper(preorder,inorder,i,inIdx+1,right);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;

        return helper(preorder,inorder,i,0,inorder.size()-1);
        
        
    }
};