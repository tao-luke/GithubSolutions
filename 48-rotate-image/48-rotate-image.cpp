class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //look at each ij once, and put it at right spot.
        int counter = 0;
        for(int l = matrix.size(); l > 0;l-=2){
            //consider each square side length
            for(int i = counter; i < matrix.size() - counter - 1; i++){
                //cout << l <<" i: " << i <<" counter: " << counter << endl;
                swap(matrix[counter][i], matrix[counter+(i-counter)][matrix.size() - counter -1]);
                swap(matrix[counter][i], matrix[matrix.size() - counter -1][matrix.size() - counter - (i-counter) - 1]);
                swap(matrix[counter][i], matrix[matrix.size() - counter -1 - (i-counter)][counter]);
            }
            counter++;
        }
    }
};