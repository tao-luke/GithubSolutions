class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = l+ (r-l)/2;
            long left = LONG_MIN;
            long right = LONG_MIN;
            if (mid-1 >= 0) left = nums[mid-1];
            if (mid+1 < nums.size()) right = nums[mid+1];
            if ((long)nums[mid] > left && (long)nums[mid] > right) return mid;
            if (nums[mid] > left) l = mid+1;
            else (r = mid-1);
        }
        return l;
    }
};