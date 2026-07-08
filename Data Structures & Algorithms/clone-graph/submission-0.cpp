/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>holder;
    Node* cloneGraph(Node* node) {
        if(!node)return node;

        if(holder.find(node) != holder.end()){
            return holder[node];
        }

        Node* clone = new Node(node->val);
        holder[node] = clone;

        for(auto nei : node->neighbors){
            clone->neighbors.push_back(cloneGraph(nei));
        }

        return clone;
    }
};
