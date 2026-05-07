class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            int k = target - nums[i];
            if(mp.find(k) == mp.end()){
                mp[nums[i]] = i;
            }else{
                return {mp[k],i};
            }
        }
        return {};
    }
};
