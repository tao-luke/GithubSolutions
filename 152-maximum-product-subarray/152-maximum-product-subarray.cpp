class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int large = nums.front();
        int small = nums.front();
        int result = large;
        for(int i = 1; i < nums.size();i++){
            int small_take_new = small * nums[i];
            int large_take_new = large * nums[i];
            
            small = min(min(nums[i], small_take_new),large_take_new);
            large = max(max(nums[i], large_take_new),small_take_new);
            
            result = max(large,result);
        }
        return result;
    }
};