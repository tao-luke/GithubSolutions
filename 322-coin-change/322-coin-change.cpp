class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> set{};
        for(const auto&n: coins){
            set.insert(n);
        }
        vector<int>dp(amount+1,0); //let dp[i] = the min ways to do amount i
        for(int i = 1; i < amount+1;i++){
            int small = INT_MAX;
            if (set.count(i) != 0){
                dp[i] = 1;
                continue;
            }
            for(const auto&n: coins){
                if (n < i && dp[i-n] != INT_MAX){
                    small = min(1+dp[i-n],small);
                }
            }
            dp[i] = small;
        }
        return (dp[amount] == INT_MAX)? -1:dp[amount];
    }
};