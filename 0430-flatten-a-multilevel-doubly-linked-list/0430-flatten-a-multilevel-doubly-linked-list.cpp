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
                Node*currNext=curr->next;
                curr->next=flatten(curr->child);
                curr->child->prev=curr;
                curr->child=NULL;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                if(currNext!=NULL){
                    curr->next=currNext;
                    currNext->prev=curr;
                }
        }
        curr=curr->next;
    }
    return head;
        
    }
};