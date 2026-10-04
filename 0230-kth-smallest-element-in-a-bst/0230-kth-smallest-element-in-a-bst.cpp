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
    int order = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }
        if (root->left != NULL) {
            int left = kthSmallest(root->left, k);
            if (left != -1) {
                return left;
            }
        }
        if (order + 1 == k) {
            return root->val;
        }
        order++;

        if (root->right != NULL) {
            int right = kthSmallest(root->right, k);
            if (right != -1) {
                return right;
            }
        }
        return -1;
    }
};