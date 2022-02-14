class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        return max(do_rob(nums,0,nums.size()-1), do_rob(nums,1,nums.size()-1));
    }
    int do_rob(const vector<int> nums, int l, int size){
        if (size < 2) return nums[l];
        int n_2 = nums[l];
        int n_1 = max(n_2, nums[l+1]);
        for(int i = l+2;i < l+size;i++){
            int n = max(n_2+nums[i],n_1);
            n_2 = n_1;
            n_1 = n;
        }
        return n_1;
    }
};