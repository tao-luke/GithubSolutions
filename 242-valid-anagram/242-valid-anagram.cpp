class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> hist{};
        for(const auto& c: s){
            hist[c]++;
        }
        for(const auto& c: t){
            if (hist.count(c) == 0) return false;
            if (hist[c] == 0) return false;
            hist[c]--;
        }
        return true;
    }
};