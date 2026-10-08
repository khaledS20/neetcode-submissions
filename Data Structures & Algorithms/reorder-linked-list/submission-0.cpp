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
    void reorderList(ListNode* head) {
        vector<int>l;
        ListNode* curr = head;

        while(curr){
            l.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int n = l.size();
        for(int i = 0; i<n/2; i++){
            curr->val = l[i];
            curr = curr->next;
            curr->val = l[n-1-i];
            curr = curr->next;
        }
        if(n%2) curr->val = l[n/2];
        // return head;
    }
};
