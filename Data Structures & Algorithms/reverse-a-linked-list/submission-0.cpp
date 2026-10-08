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
        vector<int>l;
        ListNode* curr = head;

        while(curr){
            l.push_back(curr->val);
            curr = curr->next;
        }

        reverse(l.begin(), l.end());

        curr = head;

        for(int i = 0; i<l.size(); i++){
            curr->val = l[i];
            curr = curr->next;
        }

        return head;
    }
};
