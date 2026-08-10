class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                result->next = l1;
                l1 = l1->next;
            }else{
                result->next = l2;
                l2 = l2->next;
            }

            result = result->next;
        }

        result->next = l1 ? l1 : l2;

        return dummy->next;
    }
};