class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>time;

        for(int i = 0; i<position.size(); i++){
            double t = ((double)target - position[i]) / speed[i];
            time.push_back({ position[i], t});
        }

        sort(time.rbegin(), time.rend());

        double carTime = 0;
        int fleet = 0;

        for(auto [b, a]: time){
            if(a > carTime){
                fleet++;
                carTime = a;
            }
        }

        return fleet;

    }
};
