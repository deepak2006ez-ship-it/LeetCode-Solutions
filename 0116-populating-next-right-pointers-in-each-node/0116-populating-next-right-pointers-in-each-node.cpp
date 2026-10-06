/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> inorder;
    Node* prev = NULL;
    void helper(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr == NULL) {
                if (!q.empty()) {
                    inorder.push_back(NULL);
                    q.push(NULL);
                    continue;
                } else {
                    break;
                }
            }
            inorder.push_back(curr);
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        int n = inorder.size() - 1;
        for (int i = n; i >= 0; i--) {
            if (inorder[i] == NULL) {
                prev = NULL;

            } else {
                inorder[i]->next = prev;
                prev = inorder[i];
            }
        }
    }
    Node* connect(Node* root) {
        if (root != NULL) {

            helper(root);
        }
        return root;
    }
};