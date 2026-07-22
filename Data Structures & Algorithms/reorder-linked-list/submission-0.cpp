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
    ListNode* revList(ListNode* head){
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;
        newHead = revList(newHead);
        ListNode* curr1 = head;
        ListNode* curr2 = newHead;
        while(curr1 && curr2){
            ListNode* temp1 = curr1->next;
            curr1->next = curr2;
            ListNode* temp2 = curr2->next;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
    }
};
