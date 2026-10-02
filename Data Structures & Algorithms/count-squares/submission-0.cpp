class CountSquares {
    private:
public:
    map<pair<int, int>, int>freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;

        int x = point[0];
        int y = point[1];

        for(auto t : freq){
            pair<int,int>item=t.first;
            if(item.first != x && item.second != y && abs(item.first - x) == abs(item.second - y)){
                int f1 = freq[{item.first, item.second}];
                int f2 = freq[{item.first, y}];
                int f3 = freq[{x, item.second}];

                count += f1 * f2 * f3;
            }
        }
        return count;
    }
};
