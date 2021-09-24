class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp table way:
        // define dp[i][j] where 1<=i<=2 and 0<=j<prices.size()
        //and dp[i][j] represents the best profit up to index j(including) with i transactions left
        // then note, dp[0] == 0 and dp[i][0] == 0, and 
        //      dp[i][j] == max(//no transaction today: dp[i][j-1],
        //                      //or we sell today and sold at the BEST time earlier:
        //                      prices[j] //earning from selling today + dp[i-1][best_day_to_buy_earlier]-                                               prices[best_day_to_buy_ealier]
        //                      )
        // AT this point! we note we only need the preivous collumn! thus constant space
        int size = prices.size();
        vector<vector<int>> dp(2,vector<int>(size,0)); //2 columns of previous and now with size of days
        int tmp = 0;

        for(unsigned char k = 1;k <= 2;k++){ //iterate down
            // cout << "iter k:" << static_cast<int>(k) << endl;
            swap(dp[0],dp[1]);
            dp[1][0] = 0;
            dp[0][0] = 0;
            tmp = -prices[0];
            for(int i = 1; i < size;i++){ //iterate sideway
                dp[1][i] = max(dp[1][i-1],prices[i]+tmp);
                //cout << "on index i:" << i << ":   "<< dp[1][i] << " tmp is : "<< tmp  << endl;
                tmp = max(tmp,dp[0][i]-prices[i]);
            }
        }
        
        return dp[1][size-1];
    }
};