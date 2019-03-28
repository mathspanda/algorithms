class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _data.push(x);
        if (_min.empty() || x <= _min.top()) {
            _min.push(x);
        }
    }
    
    void pop() {
        int x = _data.top();
        _data.pop();
        if (x == _min.top()) {
            _min.pop();
        }
    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _min.top();
    }
private:
    std::stack<int> _data;
    std::stack<int> _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
