class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(const auto&n: nums){
            target+=n;
        }
        if (target % 2 != 0) return false;
        target/=2;
        bool dp[target+1];
        for(int i = 0; i < target+1;i++){
            dp[i]= false;
        }
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++){
            for(int w = target; w>= nums[i]; w--){
                dp[w] = dp[w] or (dp[w-nums[i]]);
            }
            // for(int j = 0;j < target+1;j++){
            //     cout << dp[j] << " ";
            // }
            // cout << endl;
            if (dp[target]) return true;
        }
        return false;
    }
};