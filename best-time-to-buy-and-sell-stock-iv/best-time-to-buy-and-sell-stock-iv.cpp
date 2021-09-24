class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k == 0) return 0;
        short size = prices.size();
        vector<vector<short>>dp(2,vector<short>(size,0));
        for(short kk = 1; kk <=k;kk++){
            swap(dp[0],dp[1]);
            dp[1][0] = 0;
            short tmp = -prices[0]; //the profit if we purchased stuff kk-1 times before day i, which starts at 1, so we loss money if we only purchase on day 0;
            for(short i = 1;i < size;i++){
                dp[1][i] = max(dp[1][i-1],static_cast<short>(prices[i]+tmp));
                tmp = max(tmp,static_cast<short>(dp[0][i]-prices[i]));
            }
        }
        return dp[1][size-1];
    }
};