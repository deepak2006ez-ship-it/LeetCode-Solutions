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
    int findInorderIdx(vector<int>&inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(val==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode*buildTree(vector<int>&preorder,vector<int>&inorder,int left,int right,int &preOrderIdx){
        if(left>right){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preOrderIdx]);
        preOrderIdx++;
        int inOrderIdx=findInorderIdx(inorder,left,right,root->val);
        root->left=buildTree(preorder,inorder,left,inOrderIdx-1,preOrderIdx);
        root->right=buildTree(preorder,inorder,inOrderIdx+1,right,preOrderIdx);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int preOrderIdx=0;
        return buildTree(preorder,inorder,0,preorder.size()-1,preOrderIdx);
        
    }
};