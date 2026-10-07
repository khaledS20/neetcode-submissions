// class MedianFinder {
// private:
//     vector<int>hold;
//     priority_queue<int, vector<int>, greater<int>>minHeap;
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         hold.push_back(num);
//         // minHeap.push(num);
//     }
    
//     double findMedian() {
//         sort(hold.begin(), hold.end());
//         // while(!minHeap.empty()){
//         //     hold.push_back(minHeap.top());
//         //     minHeap.pop();
//         // }
//         int n = hold.size();
//         if(n%2) return hold[n/2];
//         return (hold[n/2] + hold[n/2 - 1]) / 2.0;
//     }
// };
class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    /*
        1) store first half in maxh, second half in minh
        2) maxh can have 1 element more than minh
    */
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(minh.size()>maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    double findMedian() {
        if(maxh.size()==minh.size()) return (maxh.top()+minh.top())/2.0;
        return maxh.top();
    }
};