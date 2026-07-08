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
        if(!head || k == 1)return head;

        ListNode* it = head;
        vector<int>v;
        while(it){
            v.push_back(it->val);
            it = it->next;
        }
        for(int i =0; i+k<=v.size(); i= i + k){
            reverse(v.begin()+i, v.begin()+i+k);
        } 

        it = head;

        for(int i =0; i<v.size(); i++){
            it->val = v[i];
            it = it->next;
        }

        return head;
    }
};
