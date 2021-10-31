class Solution {
public:
    int countBinarySubstrings(string s) {
        int previous = 0;
        int current = 0;
        char lastChar = s[0];
        int ans = 0;
        for(const auto&n: s){
            if (n == lastChar) current++;
            else{
                ans+=min(previous,current);
                previous = current;
                current = 1;
            }
            lastChar = n;
        }
        ans+=min(previous,current);
        return ans;
    }
};