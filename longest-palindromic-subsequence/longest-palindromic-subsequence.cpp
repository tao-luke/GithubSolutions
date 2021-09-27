class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // even the best case, we would need to go through each item and check if it is a palindrome which requires n each time. n^2 at best
        // we can do this dp, let big[i][l] = represent the longest palindrome between range i and j=i+(l-1)
        // recursively, we can deduce that big[i][l] = big[i+1][j-1]+2 if s[i] == s[j]. or if s[i] != s[j], we take max(big[i][j-1],big[i+1][j]).
        // we can make this table by going through each elem of the array and try end range of n where 1<=n<=size of s.
        // BUT note we only need results from the last l, we can make our memeory O(n) with this. the run-time is n^2 as we go n iter and n ties at each elem
        
        // siwtch the i and l for how c++ works
        short size = s.size();
        if (size < 2) return 1;
        vector<vector<short>> big(3,vector<short>(size,1)); //min 1
        for(short i = 0;i < size-1;i++){ //length 2 process
            short j = i+1;
            if (s[i] == s[j]){
                big[2][i] = 2;
            }
        }
        if (size < 3) return big[2][0];
        
        //size at least 3
        for(short l = 3;l <= size;l++){ //length considered
            swap(big[1],big[2]); // move 2 down 1
            swap(big[2],big[0]); //bring 1 to the bottom and 0 up to top to be updated
            for(short i = 0;i <= size-l;i++){ //start index
                short j = i+l-1; //end index
                if (s[i] == s[j]){
                    big[2][i] = 2+big[0][i+1]; //this wouldnt go out of bound
                }else{
                    big[2][i] = max(big[1][i],big[1][i+1]);
                }
                // cout << "i,j = (" << i <<" ,"<<j<<") and the max pal is:" << big[2][i] << endl; 
            }
        }
        return big[2][0];
    }
};