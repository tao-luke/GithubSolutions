class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{};
        for(const auto& n: nums){
            if (dp.empty() || n > dp.back()){
                dp.push_back(n);
                continue;
            }
            int index = lower_bound(dp.begin(),dp.end(),n) - dp.begin();
            dp[index] = n;
        }
        return dp.size();
    }

};