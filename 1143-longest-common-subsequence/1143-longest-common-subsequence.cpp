class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      //dp[i][j]
      vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0)); //dp[i][j] be the target for index 0 to including i, and 0 to including j
      int ans = 0;
      for(int i = 0; i < text1.size(); i++){
        for(int j = 0; j < text2.size(); j++){
          int max_new = dp[i][j];
          if (i != 0) max_new = max(max_new, dp[i-1][j]);
          if (j != 0) max_new = max(max_new, dp[i][j-1]);
          if (text1[i] == text2[j]){
            if (i != 0 && j != 0) max_new = max(dp[i-1][j-1]+1,max_new);
            else max_new = max(1, max_new);
          }
          dp[i][j] = max_new;
          ans = max(ans, max_new);
        }
        // for(const auto& vec: dp){
        //   for(const auto& n: vec){
        //     cout << n << " ";
        //   }
        //   cout << endl;
        // }
        // cout << "........" << endl;
      }
      return ans;
    }
};