/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    int pointer=-1;
    vector<TreeNode*>inorder;
    void helper(TreeNode*root){
        if(root==NULL){
            return;
        }
        helper(root->left);
        inorder.push_back(root);
        helper(root->right);
    }
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
       
        pointer++;
        return inorder[pointer]->val;
        
    }
    
    bool hasNext() {
        int n=inorder.size()-1;
        int elementRightToPointer=n-pointer;
        return elementRightToPointer>=1;

        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */