/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode*reverse(ListNode*head,ListNode*tail){
    tail->next=NULL;
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*currGroupStart=head;
        ListNode*curr=head;
        int count=1;
        while(curr!=NULL){
            curr=curr->next;
            if(curr!=NULL){
                count++;
            }
            if(count==k){
                ListNode*nextGroup=curr->next;
                ListNode*revHead=reverse(head,curr);
                ListNode*prevHead=reverseKGroup(nextGroup,k);
                currGroupStart->next=prevHead;
                return revHead;



            }
        }
        return head;

        
    }
};