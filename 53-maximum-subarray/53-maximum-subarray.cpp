class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long ans = LONG_MIN;
        long local = 0;
        for(const auto& n: nums){
            local+=n;
            ans = max(ans,local);
            local = max((long)0,local);
        }
        return ans;
    }
};