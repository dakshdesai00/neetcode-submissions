class Solution {
public:
    int helper(int index, vector<int>& nums, vector<int>& dp, int endIndex){
        if(index >= endIndex) return 0;
        if(dp[index] != -1) return dp[index];
        // i can either rob and go to next that i can or just dont rob this one
        int ro = helper(index + 2, nums, dp, endIndex) + nums[index];
        int dontro = helper(index + 1, nums, dp, endIndex);
        return dp[index] = max(ro,dontro);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        vector<int> dp1(nums.size(),-1);
        return max(helper(0,nums,dp, nums.size() - 1),helper(1,nums,dp1, nums.size()));
    }
};
