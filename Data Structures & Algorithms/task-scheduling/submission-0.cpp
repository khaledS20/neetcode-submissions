class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>maxHeap;
        queue<pair<int, int>>repo;
        unordered_map<char, int>freq;

        for(auto task : tasks)freq[task]++;
        for(auto &[a, b] : freq)maxHeap.push(b);

        int time = 0;

        while(!maxHeap.empty() || !repo.empty()){
            time++;
            if(!maxHeap.empty())
            {
                int top = maxHeap.top();maxHeap.pop();
                top--;
                if(top){
                    repo.push({top, time + n});
                }
            }
            if(!repo.empty() && time == repo.front().second){
                int front =  repo.front().first;
                repo.pop();
                maxHeap.push(front);
            }
        }
        return time;
    }
};
