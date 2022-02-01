class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int large = nums.front();
        int small = nums.front();
        int result = large;
        for(short i = 1; i < nums.size();i++){
            int small_copy = small;
            
            small = min(min(nums[i], small * nums[i]),large * nums[i]);
            large = max(max(nums[i], large * nums[i]),small_copy * nums[i]);
            
            result = max(large,result);
        }
        return result;
    }
};