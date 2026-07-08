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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *iterator = new ListNode(0);
        ListNode *result = iterator;


        while( list1 && list2)
        {
            if(list1->val > list2->val){
                result->next = list2;
                list2 = list2->next;
            }else{
                result->next = list1;
                list1 = list1->next;
            }
            result = result->next;
        }

        if(list1)result->next = list1;
        else if(list2) result->next = list2;

        return iterator->next;  
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        ListNode* result = lists[0];
        int n = lists.size();

        for(int i =1; i<n; i++){
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};
