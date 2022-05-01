class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if (word.size() == match_from(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    int match_from(int i, int j, vector<vector<char>>& board, string& word, int from){
        if (i < 0 || j < 0 || j >= board[0].size() || i >= board.size() || from >= word.size() || board[i][j] != word[from]){
            return 0;
        }
        char tmp = board[i][j];
        board[i][j] = '*';
        int result = 1 + max({match_from(i-1,j,board,word,from+1),match_from(i,j-1,board,word,from+1),match_from(i,j+1,board,word,from+1),match_from(i+1,j,board,word,from+1)});
        board[i][j] = tmp;
        return result;
    }
};