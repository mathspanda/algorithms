class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        std::stack<int> temp;
        while (!_data.empty()) {
            temp.push(_data.top());
            _data.pop();
        }
        temp.push(x);
        while (!temp.empty()) {
            _data.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = _data.top();
        _data.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return _data.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _data.empty();
    }
private:
    std::stack<int> _data;    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
 