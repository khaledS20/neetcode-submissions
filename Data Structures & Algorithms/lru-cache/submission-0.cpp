class LRUCache {
    list<pair<int, int>>l;
    unordered_map<int, list<pair<int, int>>::iterator>hash;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
     if(hash.find(key) == hash.end())return -1;
     l.splice(l.begin(), l, hash[key]);
     return hash[key]->second; 
    }
    void put(int key, int value) {
     if(hash.find(key) != hash.end()){
     l.splice(l.begin(), l, hash[key]);
     hash[key]->second = value;  
     return;
     }
     if(l.size() == size){
        int oldKey = l.back().first;
        l.pop_back();
        hash.erase(oldKey);
     }
     l.emplace_front(key, value);
     hash[key] = l.begin();
    }
};
