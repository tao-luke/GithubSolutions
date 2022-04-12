class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        int r = 0;
        int ans = 0;
        int local = 0;
        unordered_map<char, int> hist{}; //char to index mapping
        while(r < s.size()){
            char c = s[r];
            if (hist.find(c) != hist.end()){
                int tmp = hist[c];
                while(l <= tmp){
                    hist.erase(s[l]);
                    l++;
                    local--;
                }
            }
            hist.insert(make_pair(c,r));
            local++;
            ans = max(ans, local);
            r++;
        }
        return ans;
    }
};