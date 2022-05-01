class Solution {
public:
    string longestPalindrome(string s) {
        bool* dp0 = new bool[s.size()];
        bool* dp1 = new bool[s.size()];
        bool* dp2 = new bool[s.size()];
        memset(dp0,1,s.size()*sizeof(bool));
        
        int result_i = 0;
        int result_l = 1;
        for(int l = 2; l <= s.size(); l++){
            for(int i = 0; i <= s.size() - l; i++){
                bool tmp = (s[i] == s[i+l-1]);
                if (l != 2){
                    tmp = tmp && dp0[i+1];
                }
                dp2[i] = tmp;
                if (dp2[i] && l > result_l){
                    result_i = i;
                    result_l = l;
                }
                //cout << "i: " << i << "  l:  " << l <<"  dp:" << dp2[i] << endl;
            }
            if (l != 2){
                swap(dp0,dp1);
                swap(dp1,dp2);
            }else{
                swap(dp1,dp2);
            }
        }
        // delete dp0;
        // delete dp1;
        // delete dp2;
        return s.substr(result_i,result_l);
    }
};