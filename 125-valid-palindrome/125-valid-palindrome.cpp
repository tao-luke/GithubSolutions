class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return helper(s,0,s.size()-1);
    }
    bool helper(const string& s, int l, int r){
        while(l < r && !((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9')))l++;
        while(l < r && !((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9')))r--;
        if (r == l) return true;
        return (s[l] == s[r]) && ((r-l+1 == 2)? (true):(helper(s,l+1,r-1)));
    }
};