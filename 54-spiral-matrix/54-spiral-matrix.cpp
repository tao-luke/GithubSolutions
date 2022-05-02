class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result{};
        int counter = m * n;
        int i = 0;
        int j = 0;
        int phase = 0; // 0 1 2 3
        int round_counter = 0;
        while(counter > 0){
            counter--;
            result.push_back(matrix[i][j]);
            if (phase == 0){
                j++;
                if (j >= n){
                    phase++;
                    i++;
                    j--;
                }
            }else if (phase == 1){
                i++;
                if (i >= m){
                    phase++;
                    i--;
                    j--;
                }
            }else if (phase == 2){
                j--;
                if (j < round_counter){
                    phase++;
                    j++;
                    i--;
                }
            }else{
                i--;
                if (i < round_counter+1 ){
                    phase = 0;
                    i++;
                    j++;
                    m--;
                    n--;
                    round_counter++;
                }
            }
        }
        return result;
    }
};