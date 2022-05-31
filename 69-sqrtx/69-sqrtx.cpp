class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int l = 0;
        int r = x/2;
        while(l < r){
            int mid = l +(r-l+1)/2;
            if (mid  <= x / mid){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};