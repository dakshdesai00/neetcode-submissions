class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = true;
            }else{
                return true;
            }
        }
        return false;
    }
};