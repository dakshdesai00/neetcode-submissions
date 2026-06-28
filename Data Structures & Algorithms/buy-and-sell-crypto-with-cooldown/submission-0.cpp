class Solution {
public:
    int helper(vector<int>& prices, int i, int canBuy, vector<vector<int>>& memo){
        if(i >= prices.size()) return 0;
        if(memo[i][canBuy] != -1) return memo[i][canBuy];
        int profit = 0;
        if(canBuy == 1){
            profit = - prices[i] + helper(prices,i+1,0,memo);
            profit = max(profit,helper(prices,i+1,1,memo)); 
        }else{
            profit = prices[i] + helper(prices, i + 2, 1, memo);
            profit = max(profit,helper(prices,i+1,0,memo));
        }
        return memo[i][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(),vector<int>(2,-1));
        return helper(prices,0,1,memo);
    }
};
