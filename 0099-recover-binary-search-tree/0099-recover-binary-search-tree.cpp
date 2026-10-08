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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void buildInorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        buildInorder(root->left);
        inorderSeq.push_back(root);
        buildInorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        buildInorder(root);
        int n = inorderSeq.size();
        for (int i = 0; i < n - 1; i++) {
            if (inorderSeq[i]->val > inorderSeq[i + 1]->val) {
                if (first == NULL) {

                    first = inorderSeq[i];
                }
                second = inorderSeq[i + 1];
            }
        }
        if (first != NULL) {

            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};