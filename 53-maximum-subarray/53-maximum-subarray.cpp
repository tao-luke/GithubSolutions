class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long best = INT_MIN;
        long localMax = best;
        for(const auto& n: nums){
            localMax = max(localMax+n, (long)n);
            best = max(localMax, best);
        }
        return best;
    }
};