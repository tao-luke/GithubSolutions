class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int counter = nums.size()-1;
        int ans = INT_MIN;
        int pos = INT_MIN;
        int neg = INT_MAX;
        for(auto ite = nums.rbegin(); ite != nums.rend(); ite++){
            if (counter == nums.size()-1){
                pos = *ite;
                neg = *ite;
            }else{
                int tmp =  *ite * neg;
                int tmp2 = *ite * pos;
                pos = max(*ite, *ite * pos);
                pos = max(pos, tmp);
                neg = min(*ite, *ite * neg);
                neg = min(neg, tmp2);
            }
            ans = max(ans,pos);
            counter--;
        }
        return ans;
    }
};