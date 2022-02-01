class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long large = nums.front();
        long small = nums.front();
        long result = large;
        for(int i = 1; i < nums.size();i++){
            long small_take_new = small * nums[i];
            long large_take_new = large * nums[i];
            
            small = min(min((long)nums[i], small_take_new),large_take_new);
            large = max(max((long)nums[i], large_take_new),small_take_new);
            
            result = max(large,result);
        }
        return result;
    }
};