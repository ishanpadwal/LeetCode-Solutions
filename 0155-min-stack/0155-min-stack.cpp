class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        int minx=(st.empty())? value: min(st.top().second, value);
        st.push({value, minx});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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