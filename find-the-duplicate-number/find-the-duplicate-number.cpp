class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // For any type of question like this where some unique ness is maintained(unique appearance or num), and we are to find the dup, the cycle algo can be used to tackle. in this case, since only one number is used and all numbers to appear is within nums.size(), we can consider this like a graph. Where each element points to another. Now with floyd cycle, we must first find the intersection point with 2 ptrs travelling at different speed. Then we reset one to zero and it can be shown from here they will eventually meet at the cycle entrance. hence the answer here.
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while(slow != fast);
        
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};