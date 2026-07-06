class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue <pair<int,int>> pq;
        for(int i = 0; i < k; i++){
            pq.push({nums[i],i});
        }
        vector<int> res;res.push_back(pq.top().front);
        for(int right = k; right < nums.length(); right++){
            
            pq.push()
        }
    }
};
