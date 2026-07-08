class TimeMap {
    map<string, map<int, string>>holder;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        holder[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = holder[key].upper_bound(timestamp);
        return it == holder[key].begin() ? "" : prev(it)->second;
    }
};
