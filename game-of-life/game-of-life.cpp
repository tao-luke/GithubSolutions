class Solution {
public:
    int get(const vector<vector<int>>& board, const int& i, const int& j) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) return board[i][j] & 1;
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        // its a bunch of ints.... just store new number in second bit bro..... this si stupid
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++) {
                int count = 0;
                count+=get(board,i-1,j-1);
                count+=get(board,i-1,j);
                count+=get(board,i-1,j+1);
                count+=get(board,i,j-1);
                count+=get(board,i,j+1);
                count+=get(board,i+1,j-1);
                count+=get(board,i+1,j);
                count+=get(board,i+1,j+1);
                if (get(board,i,j)){
                    if (count == 2 || count == 3) board[i][j] = board[i][j] | 2;
                }else{
                    if (count == 3) board[i][j] = board[i][j] | 2;
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size();j++){
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};