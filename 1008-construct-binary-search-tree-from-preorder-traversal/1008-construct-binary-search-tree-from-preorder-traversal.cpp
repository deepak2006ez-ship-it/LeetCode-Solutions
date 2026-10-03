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
    TreeNode* buildTree(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = buildTree(root->left, val);
        } else {
            root->right = buildTree(root->right, val);
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for (auto& val : preorder) {
            root = buildTree(root, val);
        }
        return root;
    }
};