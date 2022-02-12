class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int result = 0;
        int local_count = 0;
        unordered_map<char,int> hist{};
        for(;r < s.size();r++){
            hist[s[r]]++;
            if (hist[s[r]] > local_count) local_count = hist[s[r]];
            while(r - l + 1 - local_count > k){
                hist[s[l]]--;
                l++;
                for(const auto& p: hist){
                    local_count = max(local_count, p.second);
                }
            }
        }
        return max(result, r-l);
    }
};