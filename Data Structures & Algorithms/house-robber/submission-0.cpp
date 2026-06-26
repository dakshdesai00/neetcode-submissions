class Solution {
public:

    int helper(int index, vector<int>& nums, vector<int>& dp){
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        // i can either rob and go to next that i can or just dont rob this one
        int ro = helper(index + 2, nums, dp) + nums[index];
        int dontro = helper(index + 1, nums, dp);
        return dp[index] = max(ro,dontro);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};
