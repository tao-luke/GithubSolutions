class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX;
        int n2 = INT_MAX;
        for(const auto& n: nums){
            if (n <= n1){
                n1 = n;
            }else if (n <= n2){
                n2 = n;
            }else{
                return true;
            }
        }
        return false;
    }
};