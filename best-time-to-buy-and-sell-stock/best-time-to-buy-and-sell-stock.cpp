class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min = prices[0];
        int maxProf = 0;
        int size = prices.size();
        for(int i = 1; i < size;i++){
            if (prices[i] - min > maxProf) maxProf = prices[i] - min;
            else if (prices[i] < min) min = prices[i];
        }
        return maxProf;
        
    }
};