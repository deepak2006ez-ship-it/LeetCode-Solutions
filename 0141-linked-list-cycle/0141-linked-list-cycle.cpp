/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*fastPtr=head;
        ListNode*slowPtr=head;
        while(fastPtr!=NULL && fastPtr->next!=NULL){
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
            if(fastPtr==slowPtr){
                return true;
            }

        }
        return false;
    }
};