class FreqStack {
public:
    FreqStack() {
        
    }
    unordered_map<int,int> freq;
    stack<pair<int,int>> maxFreq;
    void push(int val) {
        freq[val]++;
        stack<pair<int,int>> tmp;
        while(!maxFreq.empty() && maxFreq.top().first > freq[val]){
            tmp.push(maxFreq.top());
            maxFreq.pop();
        }
        maxFreq.push({freq[val],val});
        while(!tmp.empty()){
            maxFreq.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        pair<int,int> top = maxFreq.top();
        maxFreq.pop();
        freq[top.second]--;
        return top.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */