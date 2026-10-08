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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        vector<int>v;

        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }

        for(int i = 0; k+i<=v.size(); i+=k){
            reverse(v.begin() + i, v.begin() + i + k);
        }

        curr = head;

        for(int i = 0; i<v.size(); i++){
            curr->val = v[i];
            curr = curr->next;
        }

        return head;
    }
};
