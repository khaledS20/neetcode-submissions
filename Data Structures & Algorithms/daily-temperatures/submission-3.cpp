class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>holder;

        int n = temperatures.size() - 1;
        vector<int>result(n+1, 0);

        for(int i = n; i>=0; i--){
            while(!holder.empty() && temperatures[i] >= temperatures[holder.top()]){
                holder.pop();
            }
            if(!holder.empty()){
                result[i] = holder.top() - i;
            }
            holder.push(i);
        }
        return result;
    }
};
