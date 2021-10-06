class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hist{};
        for(const auto& n: wordDict){
            hist.insert(n);
        }
        vector<int> memo(s.size(),-1);
        return helper(s,0,hist,memo); // if its possible to break string starting from 0
    }
    bool helper(const string& s, size_t i, const unordered_set<string>& hist,vector<int>& memo){
        
        if (i == s.size()) return true;
        
        //if string is breakable starting from index i is ALREADY determined:
        if (memo[i] != -1) return memo[i];
        
        //else, we need to determine if we can break starting from i
        //thus we need to consider all substr starting from i.
        for(int end = i+1;end <= s.size();end++){
            if (hist.find(s.substr(i,end-i)) != hist.end() and helper(s,end,hist,memo)){
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
};