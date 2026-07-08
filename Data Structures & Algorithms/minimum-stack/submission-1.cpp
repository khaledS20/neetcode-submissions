class MinStack {
    stack<int>mainStack;
    stack<int>minStack;
public:
    MinStack() {}
    
    void push(int val) {
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
        mainStack.push(val);
    }
    
    void pop() {
        if(!minStack.empty() && minStack.top() == mainStack.top()){
            minStack.pop();
        }
        if(!mainStack.empty()){
            mainStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
