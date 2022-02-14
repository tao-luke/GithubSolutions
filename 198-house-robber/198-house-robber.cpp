class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        int n_2 = nums[0];
        int n_1 = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size();i++){
            int n = max(n_2+nums[i],n_1);
            n_2 = n_1;
            n_1 = n;
        }
        return n_1;
    }
};