class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int v1 = accumulate(gas.begin(), gas.end(), 0);
        int v2 = accumulate(cost.begin(), cost.end(), 0);

        if(v1 < v2)return -1;

        int start = 0;
        int tank = 0;

        for(int i = 0; i<gas.size(); i++){
            tank+=gas[i]-cost[i];

            if(tank < 0){
                tank = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
