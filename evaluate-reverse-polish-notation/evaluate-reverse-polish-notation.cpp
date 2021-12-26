class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<string(const string& a, const string& b)>> mapf {
            {"+", [](const string& a, const string& b){ return to_string(stoi(a) + stoi(b)); }},
            {"-", [](const string& a, const string& b){ return to_string(stoi(a) - stoi(b)); }},
            {"*", [](const string& a, const string& b){ return to_string(stoi(a) * stoi(b)); }},
            {"/", [](const string& a, const string& b){ return to_string(stoi(a) / stoi(b)); }}
        };
        stack<string> hist{};
        for(const auto& s: tokens) {
            if (mapf.count(s)) {
                string tmp = hist.top();
                hist.pop();
                string tmp2 = hist.top();
                hist.pop();
                hist.push(mapf[s](tmp2,tmp));
            }else{
                hist.push(s);
            }
        }
        return stoi(hist.top());
    }
};