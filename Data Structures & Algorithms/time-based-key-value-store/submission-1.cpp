class TimeMap {
    unordered_map<string, map<int, string>>container;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        container[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = container[key].upper_bound(timestamp);
        return it == container[key].begin() ? "" : prev(it)->second;
    }
};
