class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0), right(n,0);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n - i;
            }else{
                right[i] = st.top() - i;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = i + 1;
            }else{
                left[i] = i - st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
            ans = max(heights[i] * (left[i] + right[i] - 1),ans);
        }
        return ans;
    }
};
