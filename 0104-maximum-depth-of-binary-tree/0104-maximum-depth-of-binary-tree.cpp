class Solution {
public:
    int height=0;
   
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        int height=0;
        if(root==NULL){
            return height;
        }
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL){
                if(!q.empty()){
                    height++;
                    q.push(NULL);
                    continue;

                }else{
                    break;

                }
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }


        }
        return height+1;
        
    }
};