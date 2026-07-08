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
        vector<int>container;
        ListNode* iterator = head;

        while(iterator){
            container.push_back(iterator->val);
            iterator = iterator->next;
        }
        int n = container.size();

        for(int i = 0; i<n/2; i++){
            head->val = container[i];
            head = head->next;
            head->val = container[n - 1 - i];
            head = head->next;
        }

        if(n%2)head->val = container[n/2];
    }
};
