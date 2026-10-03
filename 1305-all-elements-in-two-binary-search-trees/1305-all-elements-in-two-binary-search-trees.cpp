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
    vector<int> as1;
    vector<int> as2;
    void inorderOf1(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderOf1(root->left);
        as1.push_back(root->val);
        inorderOf1(root->right);
    }
    void inorderOf2(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderOf2(root->left);
        as2.push_back(root->val);
        inorderOf2(root->right);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorderOf1(root1);
        inorderOf2(root2);
        int n = as1.size() + as2.size();
        vector<int> ans(n, 0);
        int i = as1.size() - 1;
        int j = as2.size() - 1;
        for (int k = n - 1; k >= 0; k--) {
            if (i >= 0 && j>=0 && as1[i] >= as2[j]) {
                ans[k] = as1[i];
                i--;
            } else if (i >= 0 && j>=0 && as2[j] > as1[i]) {
                ans[k] = as2[j];
                j--;
            } else {
                while (i >= 0) {
                    ans[k] = as1[i];
                    i--;
                    k--;
                }
                while (j >= 0) {
                    ans[k] = as2[j];

                    j--;
                    k--;
                }
            }
        }
        return ans;
    }
};