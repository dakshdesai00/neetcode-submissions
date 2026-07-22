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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1001);
        ListNode* curr = dummy;
        bool over = false;
        while(!over){
            int minNum = INT_MAX;
            int k = -1;
            over = true;
            for(int i = 0; i < lists.size(); i++){
                if(!lists[i]) continue;
                if(lists[i]) over = false;
                if(minNum >= lists[i]->val){
                    minNum = lists[i]->val;
                    k = i;
                }
            }
            if(!over){
                curr->next = lists[k];
                lists[k] = lists[k]->next;
                curr = curr->next;
            }else{
                break;
            }
        }
        return dummy->next;
    }
};
