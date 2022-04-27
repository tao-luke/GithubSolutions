class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> count{};
        for(const auto& c: s){
            count[c]++;
        }
        for(const auto& c: t){
            count[c]--;
        }
        for(const auto& p: count){
            if (p.second != 0) return false;
        }
        return true;
    }
};