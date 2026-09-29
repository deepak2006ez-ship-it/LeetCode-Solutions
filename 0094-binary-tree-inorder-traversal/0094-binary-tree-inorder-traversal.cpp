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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else if (curr->left != NULL) {
                // find inoreder predecssor of curr;
                TreeNode* predecessor = curr->left;
                while (predecessor->right != NULL &&
                       predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == NULL) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else if (predecessor->right == curr) {
                    predecessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};