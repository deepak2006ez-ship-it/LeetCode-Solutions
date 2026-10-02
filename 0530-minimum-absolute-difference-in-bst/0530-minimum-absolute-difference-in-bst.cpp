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
    vector<int>inorderSeq;
    void helper(TreeNode*root){
        if(root==NULL){
            return;
        }
        helper(root->left);
        inorderSeq.push_back(root->val);
        helper(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        int ans=INT_MAX;
        for(int i=1;i<inorderSeq.size();i++){
            ans=min(ans,inorderSeq[i]-inorderSeq[i-1]);
           
        }
        return ans;
        
    }
};