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
    int heights=0;
    void depthSearch(TreeNode* root,int height){
        if(root==NULL){
            return;
        }
        heights=max(height,heights);

        depthSearch(root->left,height+1);
        depthSearch(root->right,height+1);
    
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        depthSearch(root,0);
        return heights+1;    
    }
};