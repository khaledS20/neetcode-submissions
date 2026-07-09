class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>result(t.size(), 0);
        stack<int>op;

        for(int i = t.size() - 1; i>= 0; i--){
            while(!op.empty() && t[i] >= t[op.top()]){
                op.pop();
            }

            if(!op.empty()) result[i] = op.top() - i;

            op.push(i);
        }

        return result;
    }
};
