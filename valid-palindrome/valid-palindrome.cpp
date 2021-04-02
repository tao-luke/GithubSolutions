class Solution {
public:
    bool validChar(int c){
        if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)) || ((c >= 48) && (c <= 57))){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        if (s.size() <2) return true;
        int size = s.size();
        int l = 0;
        int r = size -1;
        while(l <= r){
            while(!(validChar(s[l]))){
                l++;
                if (l >= size) return true;
            }
            while(!(validChar(s[r]))){
                r--;
                if (r < 0) return true;
            }
            if (s[l] != s[r]){
                if ((s[l] >= 48) && (s[l] <= 57)) return false;
                if ((s[r] >= 48) && (s[r] <= 57)) return false;
                if (abs(s[l]-s[r]) != 32) return false;
            }
            
            l++;
            r--;
        }
        return true;
    }
};