class Solution {
public:
    int mySqrt(int x) {
        //easy binary search problem but weird to write up on the spot
        // easy intuiotion: since we are calculating the floor of the sqrt, the left ptr would either end as ans-1 or ans. We can then just always overshoot the left, and wait for the right to converage behind it.
        int l = 0;
        int r = x;
        if (x == 0) return 0;
        if (x < 4 ) return 1;
        while(l <= r){ //while they are proper
            int mid = l+(r-l)/2;
            if (mid > x/mid){
               // too big
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return r;
        // 0 1 2 3 4 5
    }
};