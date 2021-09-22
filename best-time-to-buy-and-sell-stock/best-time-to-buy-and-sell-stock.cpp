class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unsigned short buy = USHRT_MAX;
        unsigned short profit = 0;
        for(const auto&n: prices){
            if (n < buy){
                buy = n;
            }else{
                if ((n - buy) > profit) profit = n-buy;
            }
        }
        return profit;
    }
};