class Solution {
public:
    int helper(const string& s, int l){
        if (l >= s.size()) return 0;
        int result = 0;
        unordered_map<char,int> seen{};
        for(int i = l; i < s.size();i++){
            if (seen.count(s[i]) != 0){
                return max(result,helper(s,(seen.find(s[i])->second)+1));
            }else{
                seen.insert(make_pair(s[i],i));
                result++;
            }
        }
        return result;
    }
    int lengthOfLongestSubstring(string s) {
        return helper(s,0);
    }
};