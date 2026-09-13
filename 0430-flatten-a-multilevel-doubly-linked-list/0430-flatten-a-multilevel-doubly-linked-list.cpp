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
                Node*nextPt=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=NULL;

                if(nextPt!=NULL){
                    while(curr->next!=NULL){
                        curr=curr->next;
                    }
                    curr->next=nextPt;
                    nextPt->prev=curr;
                }


            }
            curr=curr->next;
        }
        return head;
    }
};