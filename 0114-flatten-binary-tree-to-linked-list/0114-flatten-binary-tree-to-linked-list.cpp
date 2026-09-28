/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> inorderSeq;
    void helper(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderSeq.push_back(root);
        helper(root->left);
        helper(root->right);
    }
    void flatten(TreeNode* root) {
        if (root != NULL) {

            helper(root);
            TreeNode* start = root;

            for (int i = 1; i < inorderSeq.size(); i++) {
                start->right = inorderSeq[i];
                start->left = NULL;
                start = inorderSeq[i];
            }
            start->right = NULL;
        }
    }
};