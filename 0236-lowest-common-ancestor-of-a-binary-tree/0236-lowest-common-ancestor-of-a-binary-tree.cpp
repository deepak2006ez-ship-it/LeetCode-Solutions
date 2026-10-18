/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p ||root==q){
            return root;
        }
        TreeNode*leftV=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightV=lowestCommonAncestor(root->right,p,q);
        if(leftV!=NULL && rightV!=NULL){
            return root;
        }
        else if(leftV!=NULL){
            return leftV;
        }
        else if(rightV!=NULL){
            return rightV;
        }
        return NULL;
    }
};