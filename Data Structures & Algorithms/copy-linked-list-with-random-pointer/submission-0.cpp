/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>hold;
        Node* curr = head;

        while(curr){
            hold[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr){
            hold[curr]->next = hold[curr->next];
            hold[curr]->random = hold[curr->random];
            curr = curr->next;
        }
        return hold[head];
    }
};
