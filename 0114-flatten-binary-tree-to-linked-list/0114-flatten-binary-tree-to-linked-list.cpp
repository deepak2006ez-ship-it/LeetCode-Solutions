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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if(curr->left==NULL){
                curr=curr->right;
            }
            else if (curr->left != NULL) {

                TreeNode* predecessor = curr->left;
                TreeNode* currRight = curr->right;
                while (predecessor->right != NULL &&
                       predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == NULL) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else if (predecessor->right == curr) {
                    currRight = curr->right;
                    
                    curr->right = curr->left;
                    curr->left=NULL;
                    predecessor->right = currRight;
                    curr = currRight;
                }
            }
        }
    }
};