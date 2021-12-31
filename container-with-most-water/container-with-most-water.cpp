class Solution {
public:
    int maxArea(vector<int>& height) {
        // The trick to realize about this qustion is that for the ans, it is a MIN of 2 heights.
        // and unless a new option appears with better heights, the outmost options are the prime.
        // With that in mind, we can init 2 ptrs from the 2 ends of the array. and keep moving them inward by 1 depdning on which side is smaller. This means we keep the longer side if possible. Hence trying all option with potentials
        int l= 0;
        int r = height.size()-1;
        int ans = 0;
        while(l != r){
            ans = max(ans, min(height[l],height[r]) * (r-l));
            if (height[r] > height[l]) {
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};