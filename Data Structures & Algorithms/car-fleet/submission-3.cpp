class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, double>>carTime;

        for(int i = 0; i<position.size(); i++){
            double t = (double)(target - position[i])/speed[i];
            carTime.push_back({position[i], t});
        }

        sort(carTime.rbegin(), carTime.rend());

        int fleet = 0;
        double maxT = 0;

        for(auto &c : carTime){
            double ct = c.second;
            if(ct > maxT){
                fleet++;
                maxT = ct;
            }
        }
        return fleet;
    }
};
