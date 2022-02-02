class Solution {
public:
    
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            //find the first number that is smaller than nums.front()
            int med = l + (r-l)/2;
            if (nums[med] < nums.front()){
                r = med;
            }else{
                l = med+1;
            }
        }
        return min(nums.front(),nums[l]);
    }
};