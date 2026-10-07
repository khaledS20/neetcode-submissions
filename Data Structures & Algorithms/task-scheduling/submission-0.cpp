class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>maxHeap;
        unordered_map<int, int>freq;
        queue<pair<int, int>>hold;
        for(auto task : tasks){
            freq[task]++;
        }
        for(auto [a, b] : freq){
            maxHeap.push(b);
        }
        int time = 0;

        while(!maxHeap.empty() || !hold.empty()){
            time++;
            if(!maxHeap.empty()){
                int t = maxHeap.top();
                maxHeap.pop();
                t--;
                if(t){
                    hold.push({t, n + time});
                }
            }
            if(!hold.empty() && hold.front().second == time){
                int f = hold.front().first;
                hold.pop();
                maxHeap.push(f);
            } 
        }
        return time;
    }
};
