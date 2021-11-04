class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0, t=0;
        for(const auto& n: nums){
            t = (~n & ~twice & once) | (~once & ~twice & n);
            twice = (once & n & ~twice) | (~once & ~n & twice);
            once = t;
        }
        return once | twice;
    }
};