/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*curr=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                Node*next=curr->next;
                curr->next=flatten(curr->child);
                curr->child->prev=curr;
                curr->child=NULL;
                if(next!=NULL){
                    while(curr->next!=NULL){
                        curr=curr->next;

                    }
                    curr->next=next;
                    next->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
        
    }
};