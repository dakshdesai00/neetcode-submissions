class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> st;
    
    void push(int x) {
       stack<int> tmp;
       while(st.size()){
            tmp.push(st.top());st.pop();
       } 
       st.push(x);
       while(tmp.size()){
            st.push(tmp.top()); tmp.pop();
       }
    }
    
    int pop() {
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        int top = st.top();
        return top;
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */