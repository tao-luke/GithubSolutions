class Solution {
public:
    int findBder(const vector<int>& nums){
        if (nums[0] <= nums[nums.size()-1]) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int m = l + (r-l)/2;
            if (m > 0 && nums[m] < nums[m-1]) return m;
            if (nums[m] > nums[r]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        // cout << l << endl;
        return l;
    }
    int findN(const vector<int>& nums, int target, int bder){
        int l = 0;
        int r = bder-1;
        if (target >= nums[bder] && target <= nums[nums.size()-1]){
            l = bder;
            r = nums.size()-1;
        }
        // cout << bder << endl;
        // cout << l << endl;
        // cout << r << endl;
        while(l < r){
            int m = l+ (r-l)/2;
            if (nums[m] == target) return m;
            else{
                if (nums[m] > target){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
        }
        if (nums[l] != target) return -1;
        return l;
    }
    int search(vector<int>& nums, int target) {
        //first find first # to be smaller than the one left of it. O(logn)
        //check from the boundary found above which side the # is in, and search in there. O(logn)
        return findN(nums,target,findBder(nums));
        
    }
};