class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int size = nums.size();
        for(auto & e: nums){
            if (e != 0){
                nums[left++] = e;
            }
        }
        for(;left < size;left++){
            nums[left] = 0;
        }
    }
};