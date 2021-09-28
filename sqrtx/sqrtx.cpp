class Solution {
public:
    // int mySqrt(int x) {
    //     //easy binary search problem but weird to write up on the spot
    //     // easy intuiotion: since we are calculating the floor of the sqrt, the left ptr would either end as ans-1 or ans. We can then just always overshoot the left, and wait for the right to converage behind it.
    //     int l = 0;
    //     int r = x;
    //     if (x == 0) return 0;
    //     if (x < 4 ) return 1;
    //     while(l <= r){ //while they are proper
    //         int mid = l+(r-l)/2;
    //         if (mid > x/mid){
    //            // too big
    //             r = mid-1;
    //         }else{
    //             l = mid+1;
    //         }
    //     }
    //     return r;
    //     // 0 1 2 3 4 5
    // }
    int mySqrt(int x){
        // 2 approaches: 
        //  1) find the first i such that p(i) is true
        //  2) find the last i such that p(i) is false
        // the difference lies which one best describes our situation.
        // suppose we pick 1), then we would have p(i) == 1 if i *i >= x, which is not what we are looking for. ex: 8, i==3 is the first i such that i*i >=x but we want 2. sO the last one that is false.
        // so the p(i) that we want to be false all the way, is 
        // p(i) == 0 if i*i>=x but we want to check for the i*i==x case 
        if (x == 0) return 0;
        int l = 1;
        int r = x/2;
        while(l < r){ //while not intersect
            
            int mid = l+(r-l+1)/2;
            if (mid == x/mid) return mid;
            if (mid > x/mid){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        return l;
    }
};