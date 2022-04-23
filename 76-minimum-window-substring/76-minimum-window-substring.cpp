class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> dict{};
        for(const auto& c: t){
            dict[c]++;
        }
        string result;
        int rel_size = 0;
        while(r < s.size()){
            char c = s[r];
            if (dict.count(c) != 0){
                if (dict[c] > 0){
                    rel_size++;
                }
                dict[c]--;
            }
            while(rel_size == t.size()){
                if (result.size() == 0 || result.size() > r - l+ 1){
                    result = s.substr(l,r-l+1);
                }
                c = s[l];
                if (dict.count(c) != 0){
                    if (dict[c] == 0){
                        rel_size--;
                    }
                    dict[c]++;
                }
                l++;
            }
            r++;
            // cout << l << "  " << r <<"   str:" << result << " rel size: " << rel_size << endl;
        }
        return result;
    }
};