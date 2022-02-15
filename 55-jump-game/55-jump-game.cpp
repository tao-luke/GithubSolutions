class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nearest_end = nums.size()-1;
        for(int i = nums.size()-2;i >= 0;i--){
            if (i + nums[i] >= nearest_end) nearest_end = i;
        }
        if (nearest_end == 0) return true;
        return false;
    }
};