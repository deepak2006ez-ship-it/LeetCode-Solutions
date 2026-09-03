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
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
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
        temp=head;//again making temp to point to starting position
        //copying random
        Node*temp1=newHead;
        bool isNull=false;
        
        while(temp!=NULL){
            isNull=((temp->random)==NULL)?true:false;
         
            Node*temp2=newHead;
            if(!isNull){
                int posOriginal=0;
                Node*randPointerOriginal=head;
                while(randPointerOriginal!=temp->random){
                    randPointerOriginal=randPointerOriginal->next;
                    posOriginal++;
                }
                int posCopy=0;
                while(posCopy!=posOriginal){
                    posCopy++;
                    temp2=temp2->next;
                }

            }else{
                temp2=NULL;
            }
           
            
            temp1->random=temp2;
            temp=temp->next;
            temp1=temp1->next;
            isNull=false;

        }

        return newHead;
        
        
        
    }
};