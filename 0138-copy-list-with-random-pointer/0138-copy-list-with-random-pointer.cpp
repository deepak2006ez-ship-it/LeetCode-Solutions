/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node*temp=head;
        Node*newHead;
        Node*prev=NULL;
        int idx=0;
        unordered_map<Node*,int>mp1;
        unordered_map<int,Node*>mp2;
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
            mp2[idx]=newNode;
            mp1[temp]=idx;
            if(idx!=0){

                prev->next=newNode;
                
            }
            prev=newNode;
            temp=temp->next;
           
            if(idx==0){
                newHead=newNode;
            }
            idx++;
        }
        temp=head;
        Node*temp1=newHead;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp1->random=NULL;

            }else{
                int idx=mp1[temp->random];
                temp1->random=mp2[idx];

            }
            
            temp1=temp1->next;
            temp=temp->next;
        }
        return newHead;
        
        
        
    }
};