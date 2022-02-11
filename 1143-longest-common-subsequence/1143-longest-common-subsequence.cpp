class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.size(), 0);
        for(const auto&c: text2){
            int p2 = 0;
            int p1 = 0;
            for(int i = 0; i < text1.size();i++){
                p1= dp[i];
                if (i == 0){
                    if (text1[i]== c) dp[i]= 1;
                }else{
                    if (text1[i]== c)
                        dp[i] = max(p2+1,dp[i]);
                    else
                        dp[i] = max(dp[i],dp[i-1]);
                }
                p2 = p1;
            }
            // for(const auto& n: dp){
            //     cout << n << " ";
            // }
            // cout << endl;
        }
        return dp[text1.size()-1];
    }
};