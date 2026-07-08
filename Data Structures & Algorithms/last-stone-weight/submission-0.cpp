class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>holder(stones.begin(), stones.end());
        while(holder.size() > 1){
            int x = holder.top();holder.pop();
            int y = holder.top();holder.pop();
            if(x!=y)holder.push(x-y);
        }
        return holder.empty()? 0:holder.top();
    }
};
