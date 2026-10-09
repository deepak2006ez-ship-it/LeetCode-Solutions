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
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        while (curr != NULL) {
            if (curr->left == NULL) {
                if (prev != NULL) {
                    if (prev->val > curr->val) {
                        if (first == NULL) {
                            first = prev;
                        }
                        second = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* inorderPredecessor = curr->left;
                while (inorderPredecessor->right != NULL &&
                       inorderPredecessor->right != curr) {
                    inorderPredecessor = inorderPredecessor->right;
                }
                if (inorderPredecessor->right == NULL) {
                    inorderPredecessor->right = curr;
                    curr = curr->left;
                } else if (inorderPredecessor->right == curr) {
                    inorderPredecessor->right = NULL;
                    if (prev != NULL) {
                        if (prev->val > curr->val) {
                            if (first == NULL) {
                                first = prev;
                            }
                            second = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                    
                }
            }
        }
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};