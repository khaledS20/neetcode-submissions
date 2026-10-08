class LRUCache {
private:
    int size;
    list<pair<int, int>>l;
    unordered_map<int, list<pair<int, int>>::iterator>lmap;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(lmap.find(key) == lmap.end()) return -1;
        l.splice(l.begin(), l, lmap[key]);
        return lmap[key]->second;
    }
    
    void put(int key, int value) {
        if(lmap.find(key) != lmap.end()){
            l.splice(l.begin(), l, lmap[key]);
            lmap[key]->second = value;
            return;
        }

        if(size == l.size()){
            int k = l.back().first;
            l.pop_back();
            lmap.erase(k);
        }

        l.emplace_front(key, value);
        lmap[key] = l.begin();

    }
};
