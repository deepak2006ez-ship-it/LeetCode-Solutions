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
    int search(vector<int>inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode*tree(vector<int>& preorder, vector<int>& inorder,int &preorderIdx,int left ,int right){
        if(left>right){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preorderIdx]);
        preorderIdx++;
        int inorderIdx=search(inorder,left,right,root->val);
        root->left=tree(preorder,inorder,preorderIdx,left,inorderIdx-1);
        root->right=tree(preorder,inorder,preorderIdx,inorderIdx+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIdx=0;
        TreeNode*root=tree(preorder,inorder,preorderIdx,0,inorder.size()-1);
        return root;
    }
};