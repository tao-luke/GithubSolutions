class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // th dp here to ask is if we can us a set of number to reach a target sum.
        unsigned char size = nums.size();
        if (size ==1) return false;
        int target = 0;
        for(const auto&n: nums){
            target+=n;
        }
        if (target % 2 != 0) return false;
        target /=2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(const auto& n: nums){
            for(int sum = target; sum > 0; sum--){
                if (sum >= n){
                    dp[sum] = dp[sum] || dp[sum - n];
                }
            }
        }
        return dp[target];
    }
};