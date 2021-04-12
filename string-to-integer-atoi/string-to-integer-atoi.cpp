class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        int size = s.size();
        bool neg = false;
        int start = 0;
        for(const auto&c: s){
            if (c != ' '){
                if (s[start] == '-'){
                    start++;
                    neg = true;
                }else if (s[start] == '+'){
                    start++;
                }
                break;
            }
            start++;
        }
        int sum = 0;
        for(;start < size;start++){
            if (s[start] > 57 || s[start] < 48) break;
            if (sum == 214748364){
                if (neg && (s[start]-48) >= 8) return INT_MIN;
                if (!neg && (s[start]-48) >= 7) return INT_MAX;
            }
            if (sum > 214748364){
                if (neg) return INT_MIN;
                return INT_MAX;
            }
            sum = sum*10 + (s[start]-48);
        }
        if (neg) return -1*sum;
        return sum;
    }
};