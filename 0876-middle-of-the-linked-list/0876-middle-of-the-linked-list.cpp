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
    ListNode* middleNode(ListNode* head) {
        int st=0;
        ListNode*temp=head;
        int idx=0;
        while(temp!=NULL){
            temp=temp->next;
            idx++;
        }
        int mid=st+(idx-st)/2;
        ListNode*temp1=head;
        int idx1=0;
        while(idx1!=mid){
            temp1=temp1->next;
            idx1++;
        }
        head=temp1;
        return head;
        
    }
};