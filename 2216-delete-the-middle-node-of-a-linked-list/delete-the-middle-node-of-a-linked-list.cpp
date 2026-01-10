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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        int noNodes = 0;
        ListNode* fkHead = head;
        while(fkHead != NULL ){
            noNodes++;
            fkHead = fkHead->next;
        }
        fkHead = head;
        int n = (noNodes/2);
        while((n-1)>0){
            fkHead = fkHead->next;
            n--;
        }
        ListNode* delNode = fkHead->next;
        fkHead->next = fkHead->next->next;
        delNode->next = NULL;
        return head;
        
    }
};