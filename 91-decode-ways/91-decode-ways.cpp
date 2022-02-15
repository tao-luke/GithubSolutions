class Solution {
public:
    int numDecodings(string s) {
        //this problem can be resolved with dp!
        //consider this sequence:
        // # 1 1 1 0 6
        // A 1 2 3 2 2
        //let dp[i] be the # of decoding for up to that index
        //at each index, we consider 2 things. if this idnex and the previous could be a 2 digit, then the # of combination we can do here is (# of ways when using this index as a single digit) + (# of ways considering this index with the previous digit).... which is just dp[i-1] + dp[i-2]. However, if this index is 0. we can't use this singularly. so we either is 0 here or if matchable as a 2 digit num with previous. then we do as needed.
        int p1 = 1;
        int p2 = 1;
        if (s.empty() || s[0] == '0') return 0;
        for(int i = 1; i < s.size();i++){
            if (s[i] == '0') p1 = 0;
            int tmp = p1;
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                    tmp = p1+p2;
            }
            p2 = p1;
            p1 = tmp;
        }
        return p1;
    }
};