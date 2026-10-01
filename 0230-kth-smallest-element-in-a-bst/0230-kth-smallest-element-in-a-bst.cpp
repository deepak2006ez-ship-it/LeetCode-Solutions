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
    void buildInorder(TreeNode*root,int k){
        if(root==NULL){
            return;
        }
        buildInorder(root->left,k);
        inorderSeq.push_back(root->val);
        buildInorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        buildInorder(root,k);
        int find=0;
        while(find<(k-1)){
            find++;
        }
        return inorderSeq[find];
    }
};