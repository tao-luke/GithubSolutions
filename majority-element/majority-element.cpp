class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int best = nums[0];
        int count = 0;
        for(const int&n:nums){
            if (n == best) count++;
            else{
                count--;
                if (count == 0) {
                    count = 1;
                    best = n;
                }
            }
        }
        return best;
    }
};