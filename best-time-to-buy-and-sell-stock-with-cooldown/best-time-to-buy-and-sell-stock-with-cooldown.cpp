class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //let dp[k][1][i] = the most profit with k+1 buys and with one stock owned on day i
        //                = max(dp[k][1][i-1],dp[k-1][0][i-2]-prices[i]) //we cant use the max from yesterday, cause its blocked.
        //then dp[k][0][i] = max(dp[k][0][i-1],dp[k][1][i-1]+prices[i])
        // then in to calculate dp[k][0][i], we need dp[k-1][0][i-2] and dp[k][1][i-1]
        //however, we dont have a k limit
        //then dp[1][i] = max(dp[1][i-1],dp[0][i-2]-prices[i]);
        //     dp[0][i] = max(dp[0][i-1],dp[1][i-1]+prices[i]);
        int dp[2][prices.size()];
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for(int i = 1; i < prices.size();i++) {
            dp[1][i] = max(dp[1][i-1],dp[0][max(0,i-2)]-prices[i]);
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]+prices[i]);
        }
        return dp[0][prices.size()-1];
    }
};