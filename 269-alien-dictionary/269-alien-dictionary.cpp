class Solution {
public:
    bool add_rule(unordered_map<char,unordered_set<char>>& rules, string a, string b){
        int c1 = 0;
        int c2 = 0;
        while(a[c1] == b[c1]){
            c1++;
            c2++;
            if (c1 < a.size() && c2 >= b.size()){
                return false;
            }
            if (c1 >= a.size() || c2 >= b.size()){
                return true;;
            }
        }
        // cout << a[c1] << "  " << b[c2] << endl;
        rules[a[c1]].insert(b[c2]);
        return true;
    }
    string alienOrder(vector<string>& words) {
        vector<char> ans_flipped{};
        unordered_map<char,unordered_set<char>> rules{};
        
        for(const auto& c: words[0]){
            if (rules.count(c) != 1) rules[c] = unordered_set<char>{};
        }
        for(int i = 0; i < words.size()-1;i++){
            for(const auto& c: words[i+1]){
                if (rules.count(c) != 1) rules[c] = unordered_set<char>{};
            }
            bool tmp = add_rule(rules,words[i],words[i+1]);
            if (!tmp) return "";
        }
        unordered_set<char> done{};
        unordered_set<char> visited{};
        for(const auto& p: rules){
            if (done.count(p.first) == 1) continue;
            bool tmp = do_dfs(rules,ans_flipped, p.first,visited,done);
            if (!tmp) return "";
        }
        string ans;
        for(int i = ans_flipped.size()-1; i >=0;i--){
            ans.push_back(ans_flipped[i]);
        }
        return ans;
    }
    bool do_dfs(const unordered_map<char,unordered_set<char>>& rules, vector<char>& ans, char c,unordered_set<char>& visited, unordered_set<char>& done){
        if (visited.count(c) == 1) return false;
        if (done.count(c) == 1) return true;
        visited.insert(c);
        if (rules.count(c) == 1){
            for(const auto& cc: rules.find(c)->second){
                bool tmp = do_dfs(rules,ans,cc,visited,done);
                if (!tmp) return false;
            }
        }
        ans.push_back(c);
        done.insert(c);
        visited.erase(c);
        return true;
    }
};