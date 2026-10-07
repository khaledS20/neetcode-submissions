class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>h;

        for(auto i : stones){
            h.push(i);
        }

        while(h.size() > 1){
            int x = h.top();
            h.pop();
            int y = h.top();
            h.pop();

            if(x != y)h.push(x - y);
        }

        return !h.empty()?h.top() : 0;
    }
};
