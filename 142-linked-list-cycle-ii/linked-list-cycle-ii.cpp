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
       // rabbit turtle method used
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            fast = head;
            while(slow != fast){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow == fast){
                return fast;
            }
        }
       }
       return NULL;
    }
};