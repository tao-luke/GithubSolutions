class Solution {
public:
    // idea: we can narrow down where the peak can be with binary search. 
    //      This is due to the fact that we know a peak must exist if we keep diviing the arr
    //          in half and iterate on the side witht he increasing side. 
    int findPeakElement(vector<int>& nums) {
        short left = 0;
        short right = nums.size()-1;
        while(true){
            if (left == right) return left;
            short mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid+1]) left = mid +1;
            else right = mid;
        }
    }
};