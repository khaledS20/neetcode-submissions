class KthLargest {
    priority_queue<int, vector<int>, greater<int>>h;
    int s;
public:
    KthLargest(int k, vector<int>& nums): s(k) {
        for(auto i : nums){
            h.push(i);
            if(h.size() > k){
                h.pop();
            }
        }
    }
    
    int add(int val) {
        h.push(val);
        if(h.size() > s) h.pop();
        return h.top();
    }
};
