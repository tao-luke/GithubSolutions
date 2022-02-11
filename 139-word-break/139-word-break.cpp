class Solution {
public:
    bool match_from(const string& s, int l, const unordered_set<string>& dict, vector<bool>& dp){
        string tmp{};
        for(int i = l; i < s.size();i++){
            tmp.push_back(s[i]);
            if (dict.count(tmp) != 0 && dp[i+1] != false){
                if (match_from(s,i+1,dict,dp)) return true;
            }
        }
        if (tmp.empty()) return true;
        dp[l] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict{};
        for(const auto& s: wordDict){
            dict.insert(s);
        }
        vector<bool> dp(s.size()+1,true);
        return match_from(s,0,dict,dp);
    }
};