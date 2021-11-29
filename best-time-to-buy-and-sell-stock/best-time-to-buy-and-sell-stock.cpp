class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //In short, we have 2 states. 
        //  a) we have a stock dp[1][i] = dp[1][i-1] or dp[0][i-1] - stock
        //  b) we do NOT have a stock dp[0][i] = dp[0][i-1] or dp[1][i-1] + stock
        // but since we can only do one buy and sell, we can just keep track of a min and profit thus
        int low = prices[0];
        int profit = 0;
        for(const auto&n: prices) {
            profit = max(profit,n - low);
            low = min(low, n);
        }
        return profit;
    }
};