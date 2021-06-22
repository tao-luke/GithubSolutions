class Solution {
public:
    short expandAt(const string& s, const short& l1, const short& l2){
        short left = (l1 == l2)? (l1-1):(l1);
        short right = (l1 == l2)? (l2+1):(l2);
        short length = (l2 == l1)? (1):(0);
        
        while(left >= 0 && right <s.size() && s[left] == s[right]){
            length+=2;
            left--;
            right++;
        }
        return length;
    }
    string longestPalindrome(string s) {
        short center = 0;
        short length = 0;
        for(short i = 0; i < s.size();i++){
            short l1 = expandAt(s,i,i);
            short l2 = expandAt(s,i,i+1);
            if (max(l1,l2) > length){
                length = max(l1,l2);
                if (l1 > l2) center = i;
                else center = (i+1) * -1;
            }
        }
        cout << center <<"    " << length << endl;
        if (center < 0){ //a half center
            center = (center*-1)-1;
            return s.substr(center+1-length/2,length);
        }
        return s.substr(center-length/2,length);
    }
};