class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp1(word2.size()+1,0);
        vector<int> dp2(word2.size()+1,0);
        for(int i = 0; i <= word2.size();i++){
            dp1[i]=i;
            dp2[i]=i;
        }
        
        for(int i = 1; i <=word1.size();i++){
            swap(dp2,dp1);
            dp2[0] = i;
            for(int j = 1; j <=word2.size();j++){
                if (word2[j-1] == word1[i-1]){
                    dp2[j] = dp1[j-1];
                }else{
                    dp2[j] = min(min(dp2[j-1],dp1[j]),dp1[j-1])+1;
                }
            }
        }
        return dp2[word2.size()];
    }
};