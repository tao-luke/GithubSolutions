class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        unordered_set<int> change{};
        for(const auto&n: nums){
            change.insert(n);
        }
        for(int i = 1; i <= target;i++){
            long tmp = 0;
            if (change.count(i) != 0)tmp++;
            for(const auto& n: nums){
                if (n < i){
                    tmp+=dp[i-n];
                }
            }
            dp[i] = tmp;
        }
        return dp[target];
    }
};