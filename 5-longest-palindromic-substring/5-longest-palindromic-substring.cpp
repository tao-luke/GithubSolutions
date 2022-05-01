class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(3, vector<bool>(s.size(),1));
        int result_i = 0;
        int result_l = 1;
        for(int l = 2; l <= s.size(); l++){
            for(int i = 0; i <= s.size() - l; i++){
                bool tmp = (s[i] == s[i+l-1]);
                if (l != 2){
                    tmp = tmp && dp[0][i+1];
                }
                dp[2][i] = tmp;
                if (dp[2][i] && l > result_l){
                    result_i = i;
                    result_l = l;
                }
                // cout << "i: " << i << "  l:  " << l <<"  dp:" << dp[i] << endl;
            }
            if (l != 2){
                swap(dp[0],dp[1]);
                swap(dp[1],dp[2]);
            }else{
                swap(dp[1],dp[2]);
            }
        }
        return s.substr(result_i,result_l);
    }
};