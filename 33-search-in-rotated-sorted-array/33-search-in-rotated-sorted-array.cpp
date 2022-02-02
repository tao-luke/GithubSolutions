class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find minimum index, and search on the side that is good
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int med = l + (r-l)/2;
            if (nums[med] < nums.front()){
                r = med;
            }else{
                l = med+1;
            }
        }
        l = (nums[l] < nums.front())? l:0;
        if (l != 0 && nums[l-1] >= target && target >= nums.front()){
            r = l-1;
            l = 0;
        }else{
            r = nums.size()-1;
        }
        while(l < r){
            int med = l + (r-l)/2;
            if (nums[med] >= target){
                r = med;
            }else{
                l = med+1;
            }
        }
        return (nums[l] == target)? l:-1;
    }
};