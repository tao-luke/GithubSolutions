class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //for this kind of problem, let us truly divide down the issue.
        // we have 2 states in owning a share, yes or no
        // we have unlimited transactions
        // we have prices.size() days of records to check
        // thus define: p[i][j] = max profit on day i with j (0<=j<=1) shares
        // the recursive rule should be: p[i][0] = max(
        //                                              p[i-1][0] //no share just like yesterday, 
        //                                              p[i-1][1]+prices[i] //had one yesterday and sold today
        //                                             )
        // or                           p[i][1] = max(p[i-1][1],p[i-2][0]-prices[i]) //if buy today, yesterday is BANNEd from use
        short size = prices.size();
        if (size < 2) return 0;
        int p_i_0 = 0; //day 1 and 0 own, 0 profit
        int p_i_1 = -prices[0]; //day 1 and 1 own, then bought day 1
        int tmp = 0; // impossible
        int tmp1 = 0;
        for(short i = 1;i < size;i++){
            tmp1 = p_i_0;
            p_i_0 = max(p_i_0,p_i_1+prices[i]);
            p_i_1 = max(p_i_1,tmp-prices[i]);
            tmp = max(tmp,tmp1);
        }
        return p_i_0;
    }
};