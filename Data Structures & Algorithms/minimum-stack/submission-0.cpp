class MinStack {
private:
    stack<int>hold;
    stack<int>minHold;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minHold.empty() || val <= minHold.top()) minHold.push(val);
        hold.push(val);
    }
    
    void pop() {
        if(!minHold.empty() && !hold.empty() && minHold.top() == hold.top()) minHold.pop();
        if(!hold.empty())hold.pop();
    }
    
    int top() {
        return hold.top();
    }
    
    int getMin() {
        return minHold.top();
    }
};
