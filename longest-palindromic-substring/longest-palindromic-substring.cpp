class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()+1][s.size()]; //dp[l][i] = true if s is palindrome with length l from index i
        memset(dp,0,sizeof(dp));
        int ans_index = 0;
        int size = 1;
        memset(dp[1],1,s.size()*sizeof(int)); //size 1 is palindrome
        for(int l = 2; l <= s.size();l++){
            for(int i = 0; i <= s.size()-l;i++){
                //cout << l << " " << i << endl;
                if (s[i] == s[i+l-1]){
                    if (l == 2 ||  dp[l-2][i+1]){
                        dp[l][i] = 1;
                        if (l > size){
                            ans_index = i;
                            size = l;
                        } // 0 1 2 
                          // 3
                    }
                }
            }
        }
        return s.substr(ans_index,size);
    }
};