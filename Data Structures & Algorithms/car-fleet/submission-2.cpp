class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>time;

        for(int i = 0; i<speed.size(); i++){
            double t = (double)(target - position[i]) / speed[i];
            time.push_back({position[i], t});
        }

        sort(time.rbegin(), time.rend());

        int fleetNumber = 0;
        double maxTime = 0;

        for(auto item : time){
            double currentTime = item.second;
            if(currentTime > maxTime){
                fleetNumber++;
                maxTime = currentTime;
            }
        }

        return fleetNumber;
    }
};
