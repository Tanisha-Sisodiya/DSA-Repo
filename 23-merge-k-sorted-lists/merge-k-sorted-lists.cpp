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
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2 ){
        if(L1 == NULL) return L2;
        if(L2 == NULL) return L1;
        if(L1->val <= L2->val){
            L1->next = mergeTwoLists(L1->next, L2);
            return L1;
        } else {
            L2->next = mergeTwoLists(L2->next, L1);
            return L2;
        }
    }
    ListNode* partnMerge(int s, int e, vector<ListNode*>& lists){
        if(s>e) return  NULL;
        if(s==e) return lists[s];
        int m = s+(e-s)/2;
        ListNode* L1 = partnMerge(s,m, lists);
        ListNode* L2 = partnMerge(m+1,e, lists);
        return mergeTwoLists(L1,L2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partnMerge(0, lists.size()-1, lists);
    }
};