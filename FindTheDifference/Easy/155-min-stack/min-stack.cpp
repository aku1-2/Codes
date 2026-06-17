class MinStack {
public:
     stack<int> s;
     stack<int> ans;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(ans.empty() || ans.top()>=value)
          ans.push(value);
    }
    
    void pop() {
        if(s.top()== ans.top())
            ans.pop();
        s.pop();


    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ans.top();
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