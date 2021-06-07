class Solution {
public:
    void helper(vector<string>& result, string&& s ,int&& open, int && close, int && max){
        if (open == max){
            int tmp = close;
            while(tmp != max){
                s.push_back(')');
                tmp++;
            }
            
            result.push_back(s);
            return;
        }
        helper(result, s + "(",open+1, move(close), move(max));
        if (open > close){
            helper(result, s + ")", move(open), close+1, move(max));
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result{};
        helper(result,"",0,0,move(n));
        return result;
    }
};