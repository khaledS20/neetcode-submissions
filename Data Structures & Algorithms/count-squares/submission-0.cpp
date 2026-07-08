class CountSquares {
    private:
public:
    map<pair<int,int>,int>freq;
    CountSquares() {
        
    }
    ~CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x = point[0];
        int y = point[1];

        for(auto item : freq){
            pair<int, int>it = item.first;
            if(x!=it.first && y != it.second && abs(x - it.first) == abs(y - it.second)){
                int f1 = freq[{it.first, it.second}];
                int f2 = freq[{x, it.second}];
                int f3 = freq[{it.first, y}];

                count+=f1*f2*f3;
            }
        }
        return count;
    }
};
