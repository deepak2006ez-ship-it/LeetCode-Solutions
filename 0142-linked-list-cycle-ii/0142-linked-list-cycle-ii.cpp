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
    ListNode *detectCycle(ListNode *head) {
        ListNode*fastPtr=head;
        ListNode*slowPtr=head;
        bool cycleExist=false;
        while(fastPtr!=NULL && fastPtr->next!=NULL){
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
            if(slowPtr==fastPtr){
                cycleExist=true;
                break;
            }

        }
        if(cycleExist){

            slowPtr=head;
            while(slowPtr!=fastPtr){
                slowPtr=slowPtr->next;
                fastPtr=fastPtr->next;
            }
        return slowPtr;
        }
        return NULL;
    }
};