class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen{};
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < s.size()){
            char c = s[r];
            if (seen.count(c) == 1){
                int index = seen[c];
                while(l <= index){
                    seen.erase(s[l]);
                    l++;
                }
            }
            seen.insert(make_pair(s[r],r));
            r++;
            ans = max(ans, (int)seen.size());
        }
        return ans;
    }
};