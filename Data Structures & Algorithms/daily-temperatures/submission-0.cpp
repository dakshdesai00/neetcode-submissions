class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(),0);
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = 0;
            }else{
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};
