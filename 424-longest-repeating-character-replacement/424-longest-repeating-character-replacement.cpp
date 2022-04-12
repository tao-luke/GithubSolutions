class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int size = 0;
        unordered_map<char,int> seen{}; //char to count mapping
        int dom_count = 0;
        while (r < s.size()){
            char c = s[r];
            seen[c]++;
            dom_count = max(dom_count, seen[c]);
            size++;
            while(size - dom_count > k){
                seen[s[l]]--;
                size--;
                l++;
            }
            ans = max(ans, size);
            dom_count = 0;
            for(const auto& p: seen){
                dom_count = max(dom_count, p.second);
            }
            r++;
        }
        return ans;
    }
};