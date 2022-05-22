class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result{};
        string tmp {};
        helper(n,0,0,tmp,result);
        return result;
    }
    void helper(int n , int open,int close ,string& tmp, vector<string>& result){
        if (open == close && open == n){
            result.push_back(tmp);
            return;
        } 
        if (open < n){
            tmp.push_back('(');
            helper(n,open+1,close,tmp,result);
            tmp.pop_back();
        }
        if (close < open){
            tmp.push_back(')');
            helper(n,open,close+1,tmp,result);
            tmp.pop_back();
        }
        return;
    }
};