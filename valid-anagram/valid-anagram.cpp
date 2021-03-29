class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<int,int> seen {};
        for(const auto & c: s){
            auto ite = seen.find(c);
            if (ite == seen.end()) seen.insert(make_pair(c,1));
            else (ite->second)++;
        }
        for(const auto & c: t){
            auto ite = seen.find(c);
            if (ite == seen.end()) return false;
            if (ite->second != 1) ite->second--;
            else seen.erase(ite);
        }
        if (seen.empty()) return true;
        return false;
    }
};