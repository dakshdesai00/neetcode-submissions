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
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* p = head;
        ListNode* q = head->next;
        while(p && q && q->next && p != q){
            p = p->next;
            q = q->next->next;
        }
        if(p == q){
            return true;
        }
        return false;
    }
};
