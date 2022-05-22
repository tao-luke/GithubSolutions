class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[0].size();j++){
                if (comp(word,0,i,j,board)) return true;
            }
        }
        return false;
    }
    bool comp(const string& word, int index, int i , int j, vector<vector<char>>& board){
        if (index >= word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||board[i][j] != word[index]) return false;
        
        board[i][j] = '#';
        
        if (comp(word,index+1,i-1,j,board) || comp(word,index+1,i,j-1,board)|| comp(word,index+1,i,j+1,board)||comp(word,index+1,i+1,j,board)) goto good;
        else{
            board[i][j] = word[index];
            return false;
        }
good:
        board[i][j] = word[index];
        return true;
    }
};