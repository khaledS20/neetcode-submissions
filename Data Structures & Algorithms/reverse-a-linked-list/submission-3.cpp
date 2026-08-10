#include<bits/stdc++.h>
using namespace std;



// struct ListNode{

//     int val;
//     ListNode *next;

//     ListNode(int val): val(val), next(nullptr){}
// };

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        vector<int>vec;
        ListNode* curr = head;

        while(curr){
            vec.push_back(curr->val);
            curr = curr->next;
        }

        reverse(vec.begin(), vec.end());
        curr = head;
        for(int i = 0; i<vec.size(); i++){
            curr->val = vec[i];
            curr = curr->next;
        }
        return head;
    }
};