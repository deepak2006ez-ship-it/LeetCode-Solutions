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
// bool helper(TreeNode* root, TreeNode* subRoot) {

// }
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }
        bool isLeftSame = helper(root->left, subRoot->left);
        bool isRightSame = helper(root->right, subRoot->right);
        return isLeftSame && isRightSame && root->val == subRoot->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }
        if (root->val == subRoot->val) {
            if (helper(root, subRoot)) {
                return true;
            }
        }
        bool leftFound=isSubtree(root->left,subRoot);
        bool rightFound=isSubtree(root->right,subRoot);
        return leftFound||rightFound;
    }
};