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
        map<Node*, Node*>nodes;
        Node*current = head;

        while(current){
            nodes[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        while(current){
            nodes[current]->next = nodes[current->next];
            nodes[current]->random = nodes[current->random];
            current = current->next;
        }

        return nodes[head];
    }
};
