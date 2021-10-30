class Solution {
public:
    void dfs(const vector<vector<bool>>&dp, vector<vector<string>>& result, vector<string>&tmp,const string& s, int index ){
        if (index == s.size()){
            result.push_back(tmp);
            return;
        }else{
            for(int l = 1;l +index-1 < s.size();l++){
                // cout << "tried: " << index << "  " << l;
                if (dp[index][l]){
                    // cout << "hit" << endl;
                    tmp.push_back(s.substr(index,l));
                    dfs(dp,result,tmp,s,index+l);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result{};
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size()+1,false));
        // such that dp[i][l] = true if [i:i+l-1] is palindrome
        // dp[x][1] = true
        // dp[i][l] = if (l >=2 ) dp[i+1][l-2] && (s[i]==s[i+l-1]) else just (s[i]==s[i+l-1])
        // and then to parition the string, go through the dp from dp[0]
        // O(n^2)
        for(int i = s.size()-1; i >= 0;i--){
            dp[i][1] = true;
            for(int l = 2;l+i-1 < s.size();l++){
                dp[i][l] = (s[i]==s[i+l-1]) && ((l == 2) or (dp[i+1][l-2]));
            }
        }
        vector<string>tmp{};
        dfs(dp,result,tmp,s,0);
        return result;
    }
};