class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty())maxHeap.push(num);
        else if(maxHeap.top() < num)minHeap.push(num);
        else maxHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())return maxHeap.top();
        else if(maxHeap.size() < minHeap.size())return minHeap.top();
        else return (maxHeap.top() + minHeap.top())/2.0;
    }
};
