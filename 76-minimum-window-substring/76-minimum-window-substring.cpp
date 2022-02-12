class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hist{};
        for(const auto& c: t){
            hist[c]++;
        }
        int expect = t.size();
        unordered_map<char,int> seen{};
        int l = 0;
        int r = 0;
        string result = "";
        int local = 0;
        for(;r < s.size();r++){
            if (hist.count(s[r]) != 0){
                int tmp = seen[s[r]];
                if (tmp < hist[s[r]]) local++;
                seen[s[r]]++;
            }
            while(local == expect){
                if (result == ""|| r-l+1 < result.size()) result = s.substr(l,r-l+1);
                if (hist.count(s[l]) != 0){

                    if (seen[s[l]] <= hist[s[l]]){
                        local--;
                    }
                    seen[s[l]]--;
                }
                l++;
                // cout <<l << "  " << r << endl;
            }
            
        }
        return result;
    }
};