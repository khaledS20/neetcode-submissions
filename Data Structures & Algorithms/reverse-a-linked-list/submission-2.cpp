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
    ListNode* reverseList(ListNode* head) {
        vector<int>holder;
        ListNode* newHead = head;

        while(newHead)
        {
            holder.push_back(newHead->val);
            newHead = newHead->next;
        }

        reverse(holder.begin(), holder.end());
        newHead = head;
        for(int i = 0; i<holder.size(); i++){
            newHead->val = holder[i];
            newHead = newHead->next;
        }

        return head;
    }
};
