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
    int search(vector<int>&inorder,int left,int right,int key){
        for(int i=left;i<=right;i++){
            if(key==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    int preOrderIdx=0;
    TreeNode*tree(vector<int>& preorder, vector<int>& inorder,int left,int right){
        if(left>right){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preOrderIdx]);
        preOrderIdx++;
        int inorderIdx=search(inorder,left,right,root->val);
        root->left=tree(preorder,inorder,left,inorderIdx-1);
        root->right=tree(preorder,inorder,inorderIdx+1,right);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree(preorder,inorder,0,inorder.size()-1);
    }
};