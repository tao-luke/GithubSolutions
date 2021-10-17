class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size(),0);
        for(auto n = text1.rbegin();n != text1.rend();n++){
            // cout << "before" << endl;
            // for(const auto& i:dp){
            //     cout << i << " ";
            // }
            int i = text2.rfind(*n);
            // while(i != string::npos){
                int tmp = i;
                if (tmp+1 == text2.size()){ //edge case
                    dp[tmp--] = 1;
                }
                //at this point, tmp is < size-1
                int curr = 0;
                int prev = dp[tmp+1];
                while(tmp >= 0){
                    curr = dp[tmp];
                    if (text2[tmp] == *n) dp[tmp] = max(prev+1,dp[tmp]);
                    else dp[tmp] = max(dp[tmp+1],dp[tmp]);
                    tmp--;
                    prev = curr;
                }
                // i = text2.rfind(*n,max(i-1,0));
            // }
            // cout << "after" << endl;
            // for(const auto& i:dp){
            //     cout << i << " ";
            // }
            // cout << endl << endl;
        }
        return dp[0];
    } // p o s t n a
};