class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hist{};
        for(const auto& s: strs){
            string cpy = s;
            sort(cpy.begin(),cpy.end());
            hist[cpy].push_back(s);
        }
        vector<vector<string>> result{};
        
        for(const auto& p: hist){
            result.push_back(p.second);
        }
        return result;
    }
};