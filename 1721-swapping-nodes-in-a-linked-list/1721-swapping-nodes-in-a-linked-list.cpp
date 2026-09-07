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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len=1;
        int start=1;
        ListNode*fromBegin=NULL;
        ListNode*temp=head;
        while(temp!=NULL){
            if(start==k){
                fromBegin=temp;
            }
            start++;
            len++;
            temp=temp->next;
        }
        int end=len-k;
        int count=1;
        ListNode*tempEnd=NULL;
        ListNode*temp1=head;
        while(temp1!=NULL){
            if(count==end){
                tempEnd=temp1;
            }
            count++;
            temp1=temp1->next;
        }


        swap(fromBegin->val,tempEnd->val);
        return head;
    }
};