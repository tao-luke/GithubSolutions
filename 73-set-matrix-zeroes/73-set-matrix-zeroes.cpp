class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // consider the first row and column as axis:
        // 1) check if 0 exist in either and save the response
        // 2) go through each 
        bool row0_empty = false;
        bool column0_empty = false;
        for(int i = 0; i < matrix.size();i++){
            if (matrix[i][0] == 0) {
                column0_empty = true;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size();i++){
            if (matrix[0][i] == 0){
                row0_empty = true;
                break;
            }
        }
        for(int i = 1; i < matrix.size();i++){
            for(int j = 1; j < matrix[0].size();j++){
                if (matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                } 
            }
        }
        for(int i = 1; i < matrix.size();i++){
            for(int j = 1; j < matrix[0].size();j++){
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if (column0_empty){
            for(int i = 0; i < matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        if (row0_empty){
            for(int i = 0; i < matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
    }
};