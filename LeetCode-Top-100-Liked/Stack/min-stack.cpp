class MinStack {
public:
    int minn = INT_MAX;
    stack<int> stk;
    stack<int> minstk;
    MinStack() {
        
    }
    void push(int value) {
        if(value < minn){
            minn = value;
        }
        minstk.push(minn);
        stk.push(value);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
        if (minstk.empty()) {
            minn = INT_MAX;
        } else {
            minn = minstk.top();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
