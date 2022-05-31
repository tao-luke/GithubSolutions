class Solution {
public:
    pair<int,int> get_one_zero(const string& s){
        int a = 0;
        int b = 0;
        for(const auto& c: s){
            if (c == '0')b++;
            else a++;
        }
        return make_pair(b,a);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1]; //dp[a][b] is the largest subset such that with m = a, n = b
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < strs.size();i++){
            //consider each str
            pair<int,int> p = get_one_zero(strs[i]);
            for(int a = m; a >= 0;a--){
                for(int b = n; b >= 0; b--){
                    if (a >= p.first && b >= p.second){
                        //plausible st we have enough for this item
                        dp[a][b] = max(dp[a][b], dp[a-p.first][b-p.second]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};