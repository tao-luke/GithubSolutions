class Solution {
public:
    bool isValid(string s) {
        stack<char> seen{};
        for(const auto& c: s){
            if (c == '(' || c=='{' || c=='['){
                seen.push(c);
            }else{
                if (seen.empty()) return false;
                if (c == ')' && seen.top() != '(') return false;
                else if (c == ']' && seen.top() != '[') return false;
                else if (c == '}' && seen.top() != '{') return false;
                seen.pop();
            }
            
        }
        return (seen.empty())? true:false;
    }
};