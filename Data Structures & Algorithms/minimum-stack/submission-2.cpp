class MinStack {
private:
    stack<int>main;
    stack<int>minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(minStack.empty() || minStack.top() >= val){
            minStack.push(val);
        }
        main.push(val);
    }
    
    void pop() {
        if(!minStack.empty()&& !main.empty() && main.top() == minStack.top()){
            minStack.pop();
        }
        if(!main.empty()){
            main.pop();
        }
    }
    
    int top() {
        if(!main.empty()) return main.top();
    }
    
    int getMin() {
        if(!minStack.empty()) return minStack.top();
    }
};
