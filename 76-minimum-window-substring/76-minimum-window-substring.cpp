class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> dict{};
        for(const auto& c: t){
            dict[c]++;
        }
        int l = 0;
        int r = 0;
        int ans_l = -1;
        int size = INT_MAX;
        int need = t.size();
        while(r < s.size()){
            char c = s[r];
            auto ite = dict.find(c);
            if (ite != dict.end()){
                if (ite->second >0)need--;
                ite->second--;
            }
            while(need <= 0 && l <= r){
                if (r - l + 1 < size){
                    //cout << l << "  " << r << endl;
                    ans_l = l;
                    size = r - l + 1;
                }
                auto ite = dict.find(s[l]);
                if (ite != dict.end()){
                    if (ite->second >= 0) need++;
                    ite->second++;
                }
                l++;
            }
             r++;
        }
        if (ans_l == -1) return "";
        return s.substr(ans_l,size);
    }
};