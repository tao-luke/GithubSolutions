class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for(int m = 1; m <= coins.size();m++){
            for(int i = 1; i <= amount;i++ ){
                int previous = dp[i];
                if (coins[m-1] <= i){
                    dp[i] = dp[i-coins[m-1]] + previous;
                }
            }
        }
        return dp[amount];
    }
};